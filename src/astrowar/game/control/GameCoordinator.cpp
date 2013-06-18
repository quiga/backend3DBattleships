/*
 * GameCoordinator.cpp
 *
 *  Created on: 2013.06.14.
 *      Author: Baarnus
 */

#include "GameCoordinator.hpp"
// Framework
#include "../../../graphics/Ois/OisFramework.hpp"

#include <iostream>
using namespace std;

GameCoordinatorListener::~GameCoordinatorListener()
{
}

GameCoordinator::GameCoordinator() :
		mGridA(NULL), mGridB(NULL), mControlProvider(NULL), mListener(NULL)
{
	OisFrameworkSingleton.addKeyListener(this);
}

GameCoordinator::~GameCoordinator()
{
	OisFrameworkSingleton.removeKeyListener(this);
}

void GameCoordinator::connectToGrids(Grid3D* gridA, Grid3D* gridB)
{
	assert(gridA);
	gridA->setGridListener(this);
	mGridA = gridA;
	assert(gridB);
	gridB->setGridListener(this);
	mGridB = gridB;
}

void GameCoordinator::connectToShipLists(CEGUI::MultiColumnList* shipListA, CEGUI::MultiColumnList* shipListB)
{
	mShipControllerA.setColumnList(shipListA);
	mShipControllerA.setDataProvider(&mShipsDataProvider);
	mShipControllerA.buildForSet();
}

// Grid listener
void GameCoordinator::onSelect(Grid3D* grid, size_t x, size_t y, size_t z)
{
	if (mControlProvider->getGamePhase() == 0)
	{
		cout << "Ship to " << grid->getNode()->getName() << ": [" << x << "," << y << "," << z << "]" << endl;
		auto ship = mControlProvider->createShip(grid);
		mControlProvider->moveShipTo(ship, { x, y, z }, grid);
	}
	else if (mControlProvider->getGamePhase() == 1)
	{
		cout << "Fire on " << grid->getNode()->getName() << ": [" << x << "," << y << "," << z << "]" << endl;
	}
}

void GameCoordinator::onNodeSearch(Ogre::SceneNode* foundNode)
{
	//
	auto ship = mControlProvider->getShipForNode(foundNode);
	if (ship)
	{
		cout << "Found ship: " << ship->getNode()->getName() << endl;
		// Set as selected
		mControlProvider->selectShip(ship);
	}
}

// Key listener
bool GameCoordinator::keyPressed(const OIS::KeyEvent &arg)
{
	if (arg.key == OIS::KC_NUMPADENTER) fireEventOnActiveGrid();
	return true;
}

bool GameCoordinator::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}

// CEGUI handler
bool GameCoordinator::handleFireButton(const CEGUI::EventArgs& arg)
{
	fireEventOnActiveGrid();
	return true;
}

// Control provider
GameControlProvider* GameCoordinator::getControlProvider() const
{
	return mControlProvider;
}

void GameCoordinator::setControlProvider(GameControlProvider* controlProvider)
{
	mControlProvider = controlProvider;
}

// Listener
GameCoordinatorListener* GameCoordinator::getListener() const
{
	return mListener;
}

void GameCoordinator::setListener(GameCoordinatorListener* listener)
{
	mListener = listener;
}

void GameCoordinator::fireEventOnActiveGrid()
{
	if (mGridA && mControlProvider->getActivePlayer() == 0) mGridA->processSelected();
	if (mGridB && mControlProvider->getActivePlayer() == 1) mGridB->processSelected();
}
