/*
 * ShipHull.hpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#ifndef SHIPHULL_HPP_
#define SHIPHULL_HPP_

// OGRE
#include <OGRE/Ogre.h>

class ShipHull
{
public:
	// Destroy
	virtual ~ShipHull();
	// Get accessors
	Ogre::SceneNode* getNode();
	Ogre::Entity* getEntity();
private:
	// Create
	ShipHull();
	// Ogre stuff
	Ogre::SceneNode* mSceneNode;
	Ogre::Entity* mEntity;
	// Shipyard must see inside
	friend class Shipyard;
};

#endif /* SHIPHULL_HPP_ */
