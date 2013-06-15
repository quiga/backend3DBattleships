/*
 * GameCoordinator.hpp
 *
 *  Created on: 2013.06.14.
 *      Author: Baarnus
 */

#ifndef GAMECOORDINATOR_HPP_
#define GAMECOORDINATOR_HPP_

#include "grid/Grid3D.hpp"
// OIS
#include <OIS/OIS.h>
// CEGUI
#include <CEGUI/CEGUI.h>
// Game
#include "shiplist/ShipListController.hpp"
#include "shiplist/AstrOWarShipListDataProvider.hpp"

class GameCoordinator: public Grid3DListener, public OIS::KeyListener
{
public:
	GameCoordinator();
	virtual ~GameCoordinator();
	// Key listener
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);
	// Grid Listener
	void onSelect(Grid3D* grid, size_t x, size_t y, size_t z);
	// Connetor
	void connectToGrids(Grid3D* gridA, Grid3D* gridB);
	void connectToShipLists(CEGUI::MultiColumnList* shipListA, CEGUI::MultiColumnList* shipListB);
	// CEGUI handler
	bool handleFireButton(const CEGUI::EventArgs& arg);
private:
	// Grids
	Grid3D *mGridA, *mGridB;
	// Ship Lists handlers
	ShipListController mShipControllerA, mShipControllerB;
	//
	AstrOWarShipListDataProvider mShipsDataProvider;
};

#endif /* GAMECOORDINATOR_HPP_ */
