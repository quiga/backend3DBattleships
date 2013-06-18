/*
 * Shipyard.cpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#include "Shipyard.hpp"
// Utils
#include "../../../tools/utils.hpp"
// OGRE
#include "../../../graphics/Ogre/OgreFramework.hpp"

Shipyard::Shipyard(Ogre::SceneManager* sceneManager) :
		mSceneManager(sceneManager)
{
	assert(mSceneManager);
}

Shipyard::~Shipyard()
{
	while (mShips.size() > 0)
		destroyShip(mShips[0]);
}

// Ship
void Shipyard::registerShipType(std::string shipTypeName, ShipTypeDescription shipTypeDescription)
{
	mShipTypes[shipTypeName] = shipTypeDescription;
}

ShipHull* Shipyard::createShip(std::string shipTypeName, Ogre::SceneNode* parentNode)
{
	// Ship number
	static int shipNumber = 0;
	// New ship hull
	ShipHull* newShip = new ShipHull;
	// Get definition
	auto description = mShipTypes[shipTypeName];
	// Create newShip stuff
	newShip->mSceneNode = parentNode->createChildSceneNode("Ship" + utils::t2str(shipNumber++));
	newShip->mEntity = mSceneManager->createEntity(description.meshFilePath);
	newShip->mSceneNode->attachObject(newShip->mEntity);
	// Add new ship to the collection
	mShips.push_back(newShip);
	// Return the new ship
	return newShip;
}

void Shipyard::destroyShip(ShipHull* ship)
{
	if (!ship) return;
	mSceneManager->destroyEntity(ship->mEntity);
	ship->mSceneNode->getParentSceneNode()->removeChild(ship->mSceneNode);
	auto fintIt = std::find(mShips.begin(), mShips.end(), ship);
	if (fintIt != mShips.end()) mShips.erase(fintIt);
}

ShipHull* Shipyard::getShip(Ogre::SceneNode* sceneNode)
{
	for (auto ship : mShips)
		if (ship->getNode() == sceneNode) return ship;
	return NULL;
}
