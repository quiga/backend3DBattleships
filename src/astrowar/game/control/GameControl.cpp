/*
 * GameControl.cpp
 *
 *  Created on: 2013.06.17.
 *      Author: Baarnus
 */

#include "GameControl.hpp"

Ogre::String GameControl::shipColorToMaterialName(ShipColor sc)
{
	switch (sc)
	{
	case SCLR_RED:
		return "HullR";
	case SCLR_GREEN:
		return "HullG";
	case SCLR_BLUE:
		return "HullB";
	case SCLR_CYAN:
		return "HullC";
	case SCLR_MAGENTA:
		return "HullM";
	case SCLR_YELLOW:
		return "HullY";
	case SCLR_WHITE:
		return "HullW";
	case SCLR_BLACK:
		return "HullK";
	default:
		return "HullG";
	}
}

GameControl::GameControl(Ogre::SceneManager* sceneManager) :
		mShipyard(sceneManager), mSelectedShip(NULL)
{
	// Init shipyard
	mShipyard.registerShipType("Destroyer", { "Destroyer.mesh" });
	mShipyard.registerShipType("Cruiser", { "Cruiser.mesh" });
	mShipyard.registerShipType("Battleship", { "Battleship.mesh" });
	mShipyard.registerShipType("Station", { "Station.mesh" });
	mShipyard.registerShipType("Carrier", { "Carrier.mesh" });
}

GameControl::~GameControl()
{
}

// Control Provider
int GameControl::getGamePhase()
{
	return 0;
}

bool GameControl::isSetReady()
{
	return false;
}

int GameControl::getActivePlayer()
{
	return 0;
}

ShipHull* GameControl::createShip(Grid3D* grid)
{
	auto ship = mShipyard.createShip("Battleship", grid->getNode());
	return ship;
}

ShipHull* GameControl::getShipForNode(Ogre::SceneNode* sceneNode)
{
	return mShipyard.getShip(sceneNode);
}

bool GameControl::moveShipTo(ShipHull* ship, std::vector<size_t> coords, Grid3D* grid)
{
	// Set coords
	ship->getNode()->setPosition(grid->coords2position(coords));
	// If valid return true
	return true;
	// If not false
}

bool GameControl::moveShipBy(ShipHull* ship, std::vector<int> coords, Grid3D* grid)
{
	return true;
}

bool GameControl::rotateShipNext(ShipHull* ship)
{
	return true;
}

bool GameControl::rotateShipPrev(ShipHull* ship)
{
	return true;
}

void GameControl::selectShip(ShipHull* ship)
{
	bool sameAsSelected = ship == mSelectedShip;
	if (mSelectedShip) colorShip(mSelectedShip, SCLR_DEFAULT);
	mSelectedShip = ship;
	if (sameAsSelected && mSelectedShip) colorShip(mSelectedShip, SCLR_CYAN);

}

void GameControl::colorShip(ShipHull* ship, ShipColor sc)
{
	ship->getEntity()->getSubEntity(0)->setMaterialName(shipColorToMaterialName(sc));
}
