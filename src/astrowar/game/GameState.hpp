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
#include "Grid3D.hpp"
#include "GameCoordinator.hpp"
// Network
#include <SFML/Network.hpp>

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
	// Torpedo
	std::shared_ptr<Grid3D> gridA;
	// Camera
	Ogre::Camera* mCamera;
	Ogre::SceneNode* mCameraNode;
	// Players
	sf::Socket* mNetPlayerSocket;
	// Game coordinator
	GameCoordinator mCoordinator;
};

#endif /* GAMESTATE_HPP_ */
