/*
 * OisOgreWindowListener.hpp
 *
 *  Created on: 2013.06.12.
 *      Author: Baarnus
 */

#ifndef OISOGREWINDOWLISTENER_HPP_
#define OISOGREWINDOWLISTENER_HPP_

#include "../Ogre/OgreFramework.hpp"
#include "../Ois/OisFramework.hpp"

class OisOgreWindowListener: public Ogre::WindowEventListener, public OIS::KeyListener
{
public:
	// Create/destroy
	OisOgreWindowListener();
	virtual ~OisOgreWindowListener();
	// Init
	void init();
	// Shut down
	void shutdown();
	// WindowEventListener
	void windowResized(Ogre::RenderWindow* rw);
	void windowClosed(Ogre::RenderWindow* rw);
	// KeyListener
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);
	// Singleton
	static OisOgreWindowListener& getSingleton();
private:
	bool mInited;
};

#endif /* OISOGREWINDOWLISTENER_HPP_ */
