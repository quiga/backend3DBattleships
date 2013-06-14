/*
 * OisCeguiInputListener.cpp
 *
 *  Created on: 2013.06.13.
 *      Author: Baarnus
 */

#include "OisCeguiInputListener.hpp"

OisCeguiInputListener::OisCeguiInputListener() :
		mInited(false)
{
}

OisCeguiInputListener::~OisCeguiInputListener()
{
	shutdown();
}

// Init
void OisCeguiInputListener::init()
{
	if (!mInited)
	{
		OisFrameworkSingleton.addKeyListener(this);
		OisFrameworkSingleton.addMouseListener(this);
		OisFrameworkSingleton.addJoyStickListener(this);
		Ogre::WindowEventUtilities::addWindowEventListener(OgreFrameworkSingleton.getRenderWindow(), this);
		OgreFrameworkSingleton.getRoot()->addFrameListener(this);
		mInited = true;
	}
}

// Shut down
void OisCeguiInputListener::shutdown()
{
	if (mInited)
	{
		OisFrameworkSingleton.removeKeyListener(this);
		OisFrameworkSingleton.removeMouseListener(this);
		OisFrameworkSingleton.removeJoyStickListener(this);
		Ogre::WindowEventUtilities::removeWindowEventListener(OgreFrameworkSingleton.getRenderWindow(), this);
		OgreFrameworkSingleton.getRoot()->removeFrameListener(this);
		mInited = false;
	}
}

//*** Listeners ***/
// KeyListener
bool OisCeguiInputListener::keyPressed(const OIS::KeyEvent &arg)
{
	CEGUI::System::getSingleton().injectKeyDown((CEGUI::Key::Scan) arg.key);
	CEGUI::System::getSingleton().injectChar(arg.text);
	return true;
}
bool OisCeguiInputListener::keyReleased(const OIS::KeyEvent &arg)
{
	CEGUI::System::getSingleton().injectKeyUp((CEGUI::Key::Scan) arg.key);
	return true;
}
// MouseListener
bool OisCeguiInputListener::mouseMoved(const OIS::MouseEvent &arg)
{
	CEGUI::System::getSingleton().injectMousePosition(arg.state.X.abs, arg.state.Y.abs);
	CEGUI::System::getSingleton().injectMouseWheelChange(arg.state.Z.rel / 120.0f);
	return true;
}
CEGUI::MouseButton convertButton(OIS::MouseButtonID id)
{
	switch (id)
	{
	case OIS::MB_Left:
		return CEGUI::LeftButton;
	case OIS::MB_Middle:
		return CEGUI::MiddleButton;
	case OIS::MB_Right:
		return CEGUI::RightButton;
	case OIS::MB_Button3:
		return CEGUI::X1Button;
	case OIS::MB_Button4:
		return CEGUI::X2Button;
	default:
		return CEGUI::NoButton;
	}
}
bool OisCeguiInputListener::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	CEGUI::System::getSingleton().injectMouseButtonDown(convertButton(id));
	return true;
}
bool OisCeguiInputListener::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	CEGUI::System::getSingleton().injectMouseButtonUp(convertButton(id));
	return true;
}
// JoyStrickListener
bool OisCeguiInputListener::buttonPressed(const OIS::JoyStickEvent &arg, int button)
{
	return true;
}
bool OisCeguiInputListener::buttonReleased(const OIS::JoyStickEvent &arg, int button)
{
	return true;
}
bool OisCeguiInputListener::axisMoved(const OIS::JoyStickEvent &arg, int axis)
{
	return true;
}
bool OisCeguiInputListener::sliderMoved(const OIS::JoyStickEvent &arg, int index)
{
	return true;
}
bool OisCeguiInputListener::povMoved(const OIS::JoyStickEvent &arg, int index)
{
	return true;
}
bool OisCeguiInputListener::vector3Moved(const OIS::JoyStickEvent &arg, int index)
{
	return true;
}
// Window Event Listener
void OisCeguiInputListener::windowResized(Ogre::RenderWindow* rw)
{
	if (rw)
	{
		unsigned w, h, d;
		int x, y;
		rw->getMetrics(w, h, d, x, y);
		CEGUI::System::getSingleton().notifyDisplaySizeChanged(CEGUI::Size(w, h));
	}
}
// Frame Listener
bool OisCeguiInputListener::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	CEGUI::System::getSingleton().injectTimePulse(evt.timeSinceLastFrame);
	return true;
}
// Singleton
OisCeguiInputListener& OisCeguiInputListener::getSingleton()
{
	static OisCeguiInputListener instance;
	return instance;
}
