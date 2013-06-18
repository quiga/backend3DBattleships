/*
 * GameControl.hpp
 *
 *  Created on: 2013.06.17.
 *      Author: Baarnus
 */

#ifndef GAMECONTROL_HPP_
#define GAMECONTROL_HPP_

#include "../GameState.hpp"
#include "../shipyard/Shipyard.hpp"
#include "GameControlProvider.hpp"

class GameControl: public GameControlProvider
{
public:
	// Ship colors
	enum ShipColor
	{
		SCLR_DEFAULT, SCLR_RED, SCLR_GREEN, SCLR_BLUE, SCLR_CYAN, SCLR_MAGENTA, SCLR_YELLOW, SCLR_WHITE, SCLR_BLACK
	};
	Ogre::String shipColorToMaterialName(ShipColor sc);
	// Create & Destroy
	GameControl(Ogre::SceneManager* sceneManager);
	virtual ~GameControl();
	// Control Provider States
	virtual int getGamePhase();
	virtual bool isSetReady();
	virtual int getActivePlayer();
	// Control Provider Ships
	virtual ShipHull* createShip(Grid3D* grid);
	ShipHull* getShipForNode(Ogre::SceneNode* sceneNode);
	virtual bool moveShipTo(ShipHull* ship, std::vector<size_t> coords, Grid3D* grid);
	virtual bool moveShipBy(ShipHull* ship, std::vector<int> coords, Grid3D* grid);
	virtual bool rotateShipNext(ShipHull* ship);
	virtual bool rotateShipPrev(ShipHull* ship);
	// Selected ship
	virtual void selectShip(ShipHull* ship);
private:
	// Coloring ship
	void colorShip(ShipHull* ship, ShipColor sc);
	// Ship source
	Shipyard mShipyard;
	// Selected ship
	ShipHull* mSelectedShip;
};

#endif /* GAMECONTROL_HPP_ */
