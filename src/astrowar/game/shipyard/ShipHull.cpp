/*
 * ShipHull.cpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#include "ShipHull.hpp"

ShipHull::~ShipHull()
{
}

ShipHull::ShipHull() :
		mSceneNode(NULL), mEntity(NULL)
{
}

// Get accessors
Ogre::SceneNode* ShipHull::getNode()
{
	return mSceneNode;
}

Ogre::Entity* ShipHull::getEntity()
{
	return mEntity;
}
