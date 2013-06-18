/*
 * Shipyard.hpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#ifndef SHIPYARD_HPP_
#define SHIPYARD_HPP_

// STD
#include <map>
// OGRE
#include <OGRE/Ogre.h>
// Game
#include "ShipHull.hpp"

class Shipyard
{
public:
	// Ship type struct
	struct ShipTypeDescription
	{
		// File Path for mesh
		Ogre::String meshFilePath;
	};
	// Create & Destroy
	Shipyard(Ogre::SceneManager* sceneManager);
	virtual ~Shipyard();
	// Ship
	void registerShipType(std::string shipTypeName, ShipTypeDescription shipTypeDescription);
	ShipHull* createShip(std::string shipTypeName, Ogre::SceneNode* parentNode);
	void destroyShip(ShipHull* ship);
	// Ship get
	ShipHull* getShip(Ogre::SceneNode* sceneNode);
private:
	std::map<std::string, ShipTypeDescription> mShipTypes;
	std::vector<ShipHull*> mShips;
	Ogre::SceneManager* mSceneManager;
};

#endif /* SHIPYARD_HPP_ */
