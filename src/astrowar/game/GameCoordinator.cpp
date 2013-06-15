/*
 * GameCoordinator.cpp
 *
 *  Created on: 2013.06.14.
 *      Author: Baarnus
 */

#include "GameCoordinator.hpp"
// Framework
#include "../../graphics/Ois/OisFramework.hpp"

#include <iostream>
using namespace std;

GameCoordinator::GameCoordinator() :
		mGridA(NULL), mGridB(NULL)
{
	OisFrameworkSingleton.addKeyListener(this);
}

GameCoordinator::~GameCoordinator()
{
	OisFrameworkSingleton.removeKeyListener(this);
}

// Key listener
bool GameCoordinator::keyPressed(const OIS::KeyEvent &arg)
{
	if (arg.key == OIS::KC_NUMPADENTER)
	{
		if (mGridA) mGridA->processSelected();
	}
	return true;
}

bool GameCoordinator::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}

void GameCoordinator::onSelect(Grid3D* grid, size_t x, size_t y, size_t z)
{
	cout << "Event on " << grid->getNode()->getName() << ": [" << x << "," << y << "," << z << "]" << endl;
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

// CEGUI handler
bool GameCoordinator::handleFireButton(const CEGUI::EventArgs& arg)
{
	if (mGridA) mGridA->processSelected();
	return true;
}
