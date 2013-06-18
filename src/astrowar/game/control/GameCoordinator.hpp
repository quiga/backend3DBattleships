/*
 * GameCoordinator.hpp
 *
 *  Created on: 2013.06.14.
 *      Author: Baarnus
 */

#ifndef GAMECOORDINATOR_HPP_
#define GAMECOORDINATOR_HPP_

#include "../grid/Grid3D.hpp"
// OIS
#include <OIS/OIS.h>
// CEGUI
#include <CEGUI/CEGUI.h>
// Game
#include "../shiplist/ShipListController.hpp"
#include "../shiplist/AstrOWarShipListDataProvider.hpp"
#include "GameControlProvider.hpp"

class GameCoordinatorListener
{
public:
	virtual ~GameCoordinatorListener();
	//
	virtual void notifyOnGameChange() = 0;
};

class GameCoordinator: public Grid3DListener, public OIS::KeyListener
{
public:
	GameCoordinator();
	virtual ~GameCoordinator();
	// Connetor
	void connectToGrids(Grid3D* gridA, Grid3D* gridB);
	void connectToShipLists(CEGUI::MultiColumnList* shipListA, CEGUI::MultiColumnList* shipListB);
	// Grid Listener
	void onSelect(Grid3D* grid, size_t x, size_t y, size_t z);
	void onNodeSearch(Ogre::SceneNode* foundNode);
	// Key listener
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);
	// CEGUI handler
	bool handleFireButton(const CEGUI::EventArgs& arg);
	// Control provider
	GameControlProvider* getControlProvider() const;
	void setControlProvider(GameControlProvider* controlProvider);
	// Listener
	GameCoordinatorListener* getListener() const;
	void setListener(GameCoordinatorListener* listener);
private:
	// Grids
	Grid3D *mGridA, *mGridB;
	void fireEventOnActiveGrid();
	// Ship Lists handlers
	ShipListController mShipControllerA, mShipControllerB;
	//
	AstrOWarShipListDataProvider mShipsDataProvider;
	// Control Provider
	GameControlProvider* mControlProvider;
	// Coordinator listener
	GameCoordinatorListener* mListener;
};

#endif /* GAMECOORDINATOR_HPP_ */
