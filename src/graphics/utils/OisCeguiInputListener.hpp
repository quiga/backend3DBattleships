/*
 * OisCeguiInputListener.hpp
 *
 *  Created on: 2013.06.13.
 *      Author: Baarnus
 */

#ifndef OISCEGUIINPUTLISTENER_HPP_
#define OISCEGUIINPUTLISTENER_HPP_

#include "../Ois/OisFramework.hpp"
#include "../Cegui/CeguiFramework.hpp"
#include "../Ogre/OgreFramework.hpp"

class OisCeguiInputListener: public OIS::KeyListener,
		public OIS::MouseListener,
		public OIS::JoyStickListener,
		public Ogre::WindowEventListener,
		public Ogre::FrameListener
{
public:
	OisCeguiInputListener();
	virtual ~OisCeguiInputListener();
	// Init
	void init();
	// Shut down
	void shutdown();
	//*** Listeners ***/
	// KeyListener
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);
	// MouseListener
	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	// JoyStrickListener
	virtual bool buttonPressed(const OIS::JoyStickEvent &arg, int button);
	virtual bool buttonReleased(const OIS::JoyStickEvent &arg, int button);
	virtual bool axisMoved(const OIS::JoyStickEvent &arg, int axis);
	virtual bool sliderMoved(const OIS::JoyStickEvent &arg, int index);
	virtual bool povMoved(const OIS::JoyStickEvent &arg, int index);
	virtual bool vector3Moved(const OIS::JoyStickEvent &arg, int index);
	// Window Event Listener
	virtual void windowResized(Ogre::RenderWindow* rw);
	// Frame Listener
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	// Singleton
	static OisCeguiInputListener& getSingleton();
private:
	bool mInited;
};

#endif /* OISCEGUIINPUTLISTENER_HPP_ */
