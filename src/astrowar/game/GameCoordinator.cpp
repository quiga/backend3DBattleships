/*
 * GameCoordinator.cpp
 *
 *  Created on: 2013.06.14.
 *      Author: Baarnus
 */

#include "GameCoordinator.hpp"

#include <iostream>
using namespace std;

GameCoordinator::GameCoordinator() :
		mGridA(NULL), mGridB(NULL)
{
}

GameCoordinator::~GameCoordinator()
{
}

// Key listener
bool GameCoordinator::keyPressed(const OIS::KeyEvent &arg)
{
	if (arg.key == OIS::KC_NUMPADENTER)
	{
	}
	return true;
}

bool GameCoordinator::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}

void GameCoordinator::onSelect(size_t x, size_t y, size_t z)
{
	cout << "Event on grid: [" << x << "," << y << "," << z << "]" << endl;
}

void GameCoordinator::connectToGrids(Grid3D* gridA, Grid3D* gridB)
{
	assert(gridA);
	gridA->setGridListener(this);
	mGridA = gridA;

	mGridB = gridB;
}
