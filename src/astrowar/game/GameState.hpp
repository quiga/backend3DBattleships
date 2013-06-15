/*
 * GameState.hpp
 *
 *  Created on: 2013.04.24.
 *      Author: baarnus
 */

#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

/** Include **/
// Tools
#include "../../graphics/Ogre/OgreState.hpp"
// Game
#include "grid/Grid3D.hpp"
#include "GameCoordinator.hpp"
#include "shipyard/Shipyard.hpp"
// Network
#include <SFML/Network.hpp>
// CEGUI
#include <CEGUI/CEGUI.h>
// STD
#include <vector>

class GameState: public OgreState, public OIS::MouseListener, public OIS::KeyListener
{
public:
	GameState(sf::Socket* connectedPlayerSocket = NULL);
	virtual ~GameState();
protected:
	// State
	void onActivate();
	void onDeactivate();
	// FrameListener
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	// Mouse Listener
	bool mouseMoved(const OIS::MouseEvent &arg);
	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	// Key listener
	bool keyPressed(const OIS::KeyEvent &arg);
	bool keyReleased(const OIS::KeyEvent &arg);
	// CEGUI handlers
	bool backButtonHandler(const CEGUI::EventArgs& arg);
	// Toggle grids
	void toggleGrids();
	// Torpedo
	std::shared_ptr<Grid3D> gridA, gridB;
	// Camera
	Ogre::Camera* mCamera;
	Ogre::SceneNode* mCameraNode;
	// Players
	sf::Socket* mNetPlayerSocket;
	// Game coordinator
	GameCoordinator mCoordinator;
	// Shipyard
	Shipyard mShipyard;

	// TMP
	std::vector<Ogre::Quaternion> mOrientations;
	ShipHull* mShip;
};

#endif /* GAMESTATE_HPP_ */
