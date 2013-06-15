/*
 * GameState.cpp
 *
 *  Created on: 2013.04.24.
 *      Author: baarnus
 */

#include "GameState.hpp"
// STD
#include <iostream>
// Frameworks
#include "../../graphics/Ois/OisFramework.hpp"
// CEGUI
#include "../../graphics/Cegui/CeguiTranslator.hpp"

using namespace std;
using namespace Ogre;
using namespace CEGUI;

GameState::GameState(sf::Socket* connectedPlayerSocket) :
		OgreState("GameState"), mCamera(NULL), mCameraNode(NULL), mNetPlayerSocket(connectedPlayerSocket), mShipyard(mSceneManager), mShip(NULL)
{
	// Create light
	Light* l = mSceneManager->createLight("MainLight");
	l->setPosition(1, 3, 4);
	// Skybox
	mSceneManager->setSkyBox(true, "Astrowar/SpaceSkyBox");
	// Orientations
	size_t numOfO = 0;
	for (float angle1 = 0.0f; angle1 < 360.0f; angle1 += 90.0f)
	{
		for (float angle2 = 0.0f; angle2 < 360.0f; angle2 += 90.0f)
		{
			cout << "GenO#" << numOfO++ << ": " << angle1 << " " << angle2 << endl;
			Ogre::Quaternion q = Ogre::Quaternion(Radian(Degree(angle1)), Ogre::Vector3::UNIT_Y)
					* Ogre::Quaternion(Radian(Degree(angle2)), Ogre::Vector3::UNIT_Z);
			mOrientations.push_back(q);
		}
	}
	for (float angle1 = 90.0f; angle1 >= -90.0f; angle1 -= 180.0f)
	{
		for (float angle2 = 0.0f; angle2 < 360.0f; angle2 += 90.0f)
		{
			cout << "GenO#" << numOfO++ << ": " << angle1 << " " << angle2 << endl;
			Ogre::Quaternion q = Ogre::Quaternion(Radian(Degree(angle1)), Ogre::Vector3::UNIT_X)
					* Ogre::Quaternion(Radian(Degree(angle2)), Ogre::Vector3::UNIT_Z);
			mOrientations.push_back(q);
		}
	}
}

GameState::~GameState()
{
}

void GameState::onActivate()
{
	// Super class
	OgreState::onActivate();
	// Camera & Viewport
	createCameraAndViewport(0);
	mCamera = getCamera(0);
	mCamera->setPosition(0, 0, 2);
	mCamera->lookAt(0, 0, 0);
	mCamera->setNearClipDistance(0.2);
	mCamera->setAutoAspectRatio(true);
	auto viewport = getViewport(0);
	viewport->setBackgroundColour(ColourValue(0.1, 0.4, 0.7));

	// CEGUI System singleton
	CEGUI::System& guiSys = CEGUI::System::getSingleton();
	// Init main menu
	guiSys.executeScriptFile("init_game.lua");
	// Translate windgets text
	translateCeguiWindow(guiSys.getGUISheet());

	mCameraNode = mSceneManager->getRootSceneNode()->createChildSceneNode("Camera Node");
	mCameraNode->attachObject(mCamera);
	// Create grids
	size_t dim = 8;
	std::vector<size_t> dimensions = { dim, dim, dim };
	gridA.reset(new Grid3D(mSceneManager, mCamera, dimensions, ColourValue(0.8, 0.3, 0.1, 0.5)));
	gridB.reset(new Grid3D(mSceneManager, mCamera, dimensions, ColourValue(0.8, 0.3, 0.1, 0.5)));
	size_t maxDimension = 0;
	for (auto d : dimensions)
		if (d > maxDimension) maxDimension = d;
	float scale = 1.0f / maxDimension;
	gridA->getNode()->setScale(scale, scale, scale);
	gridB->getNode()->setScale(scale, scale, scale);
	mCoordinator.connectToGrids(gridA.get(), gridB.get());
//	gridB->getNode()->translate(3, 0, 0);
	// Init shipyard
	mShipyard.registerShipType("Destroyer", { "Destroyer.mesh" });
	mShipyard.registerShipType("Cruiser", { "Cruiser.mesh" });
	mShipyard.registerShipType("Battleship", { "Battleship.mesh" });
	mShipyard.registerShipType("Station", { "Station.mesh" });
	mShipyard.registerShipType("Carrier", { "Carrier.mesh" });

	auto ship = mShipyard.createShip("Carrier", gridA->getNode());
	ship->getNode()->setPosition(gridA->coords2position( { 0, 0, 0 }));
	ship = mShipyard.createShip("Cruiser", gridA->getNode());
	ship->getNode()->setPosition(gridA->coords2position( { 4, 1, 0 }));
	ship = mShipyard.createShip("Battleship", gridA->getNode());
	ship->getNode()->setPosition(gridA->coords2position( { 3, 2, 4 }));
	ship = mShipyard.createShip("Station", gridA->getNode());
	ship->getNode()->setPosition(gridA->coords2position( { 7, 6, 5 }));

	mShip = mShipyard.createShip("Carrier", gridB->getNode());
	mShip->getNode()->setPosition(gridB->coords2position( { 3, 3, 3 }));

	gridB->getNode()->setVisible(false);
	// Add to listeners
	OisFrameworkSingleton.addMouseListener(this);
	OisFrameworkSingleton.addKeyListener(this);
	// Back Button
	CEGUI::PushButton* backButton = static_cast<CEGUI::PushButton*>(guiSys.getGUISheet()->getChildRecursive("Game/Menu/BackButton"));
	if (backButton) backButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameState::backButtonHandler, this));
	// Fire Button
	CEGUI::PushButton* fireButton = static_cast<CEGUI::PushButton*>(guiSys.getGUISheet()->getChildRecursive("Game/Control/FireButton"));
	if (fireButton) fireButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameCoordinator::handleFireButton, &mCoordinator));
	// Ship list
	CEGUI::MultiColumnList* shipList1 = static_cast<CEGUI::MultiColumnList*>(guiSys.getGUISheet()->getChildRecursive("Game/Player1Panel/ShipList"));
	if (shipList1)
	{
		mCoordinator.connectToShipLists(shipList1, NULL);
	}
}

void GameState::onDeactivate()
{
	// Destroy
	mSceneManager->destroySceneNode(mCameraNode);
	// Destroy Grids
	gridA.reset();
	gridB.reset();
	// Remove from listeners
	OisFrameworkSingleton.removeMouseListener(this);
	OisFrameworkSingleton.removeKeyListener(this);
	// CEGUI System singleton
	CEGUI::System& guiSys = CEGUI::System::getSingleton();
	// Init main menu
	guiSys.executeScriptFile("shutdown_game.lua");
	// Super class
	OgreState::onDeactivate();
}

bool GameState::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	gridA->update(evt.timeSinceLastFrame);
	gridB->update(evt.timeSinceLastFrame);
	return true;
}

bool GameState::mouseMoved(const OIS::MouseEvent &arg)
{
	if (arg.state.buttonDown(OIS::MB_Right))
	{
		mCameraNode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Radian(-0.005 * arg.state.X.rel));
		mCameraNode->rotate(Ogre::Vector3::UNIT_X, Ogre::Radian(-0.005 * arg.state.Y.rel));
	}

	return true;
}

bool GameState::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return true;
}

bool GameState::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return true;
}

bool GameState::keyPressed(const OIS::KeyEvent &arg)
{
	if (arg.key == OIS::KC_SPACE)
	{
		toggleGrids();
	}
	static size_t orient_index = 0;
	if (orient_index > 0 && arg.key == OIS::KC_LEFT) orient_index--;
	if (orient_index < 23 && arg.key == OIS::KC_RIGHT) orient_index++;
	cout << "New orientation index: " << orient_index << ", Orientation: " << endl;
	mShip->getNode()->setOrientation(mOrientations[orient_index]);
	return true;
}

bool GameState::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}

// CEGUI handlers
bool GameState::backButtonHandler(const CEGUI::EventArgs& arg)
{
	popState();
	return true;
}

// Toggle grids
void GameState::toggleGrids()
{
//	Ogre::Vector3 tmp = gridA->getNode()->getPosition();
//	gridA->getNode()->setPosition(gridB->getNode()->getPosition());
	gridA->getNode()->flipVisibility();
//	gridB->getNode()->setPosition(tmp);
	gridB->getNode()->flipVisibility();
}
