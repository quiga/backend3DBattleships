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
		OgreState("GameState"), mCamera(NULL), mCameraNode(NULL), mNetPlayerSocket(connectedPlayerSocket)
{
	// Create light
	Light* l = mSceneManager->createLight("MainLight");
	l->setPosition(1, 3, 4);
	// Skybox
	mSceneManager->setSkyBox(true, "Astrowar/SpaceSkyBox");
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
	size_t dim = 5;
	std::vector<size_t> dimensions = { dim, dim, dim };
	gridA.reset(new Grid3D(mSceneManager, mCamera, dimensions, ColourValue(0.8, 0.3, 0.1, 0.5)));
	size_t maxDimension = 0;
	for (auto d : dimensions)
		if (d > maxDimension) maxDimension = d;
	float scale = 1.0f / maxDimension;
	gridA->getNode()->setScale(scale, scale, scale);
	mCoordinator.connectToGrids(gridA.get(), NULL);
	// Add to listeners
	OisFrameworkSingleton.addMouseListener(this);
	OisFrameworkSingleton.addKeyListener(this);
	// Back Button
	CEGUI::PushButton* backButton = static_cast<CEGUI::PushButton*>(guiSys.getGUISheet()->getChildRecursive("Game/Menu/BackButton"));
	if (backButton) backButton->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameState::backButtonHandler, this));
}

void GameState::onDeactivate()
{
	cout << "Deactivate game" << endl;
	// Destroy
	mSceneManager->destroySceneNode(mCameraNode);
	// Destroy Grids
	gridA.reset();
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
	gridA->handleInput(OisFrameworkSingleton.getKeyboard(), OisFrameworkSingleton.getMouse(), evt.timeSinceLastFrame);
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
