/*
 * GameControlProvider.hpp
 *
 *  Created on: 2013.06.17.
 *      Author: Baarnus
 */

#ifndef GAMECONTROLPROVIDER_HPP_
#define GAMECONTROLPROVIDER_HPP_

// STD
#include <vector>
// GAME
#include "../shipyard/ShipHull.hpp"
#include "../grid/Grid3D.hpp"

class GameControlProvider
{
public:
	virtual ~GameControlProvider();
	// State
	virtual int getGamePhase() = 0;
	virtual bool isSetReady() = 0;
	virtual int getActivePlayer() = 0;
	// Ship management
	virtual ShipHull* createShip(Grid3D* grid) = 0;
	virtual ShipHull* getShipForNode(Ogre::SceneNode* sceneNode) = 0;
	virtual bool moveShipTo(ShipHull* ship, std::vector<size_t> coords, Grid3D* grid) = 0;
	virtual bool moveShipBy(ShipHull* ship, std::vector<int> coords, Grid3D* grid) = 0;
	virtual bool rotateShipNext(ShipHull* ship) = 0;
	virtual bool rotateShipPrev(ShipHull* ship) = 0;
	// Selected ship
	virtual void selectShip(ShipHull* ship) = 0;
};

#endif /* GAMECONTROLPROVIDER_HPP_ */
