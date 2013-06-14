/*
 * OisFramework.hpp
 *
 *  Created on: 2013.06.12.
 *      Author: Baarnus
 */

#ifndef OISFRAMEWORK_HPP_
#define OISFRAMEWORK_HPP_

#include <OIS/OIS.h>

class OisFrameworkInitHelper
{
public:
	virtual ~OisFrameworkInitHelper();
	// Window handler
	virtual unsigned getWindowHnd() = 0;
	// Is input exclusive?
	virtual bool isInputExlusive();
};

class OisFramework: public OIS::KeyListener, public OIS::MouseListener, public OIS::JoyStickListener
{
public:
	// Create/Destroy
	OisFramework();
	virtual ~OisFramework();
	// Init
	void init(OisFrameworkInitHelper* initHelper);
	// Shut down
	void shutdown();
	// Capture
	void capture();
	//*** Getters ***/
	OIS::Keyboard* getKeyboard();
	OIS::Mouse* getMouse();
	OIS::JoyStick* getJoystick(size_t i);
	size_t getNumOfJoysticks();
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
	// Broadcast to listeners
	// Add listener
	void addKeyListener(OIS::KeyListener* keyListener);
	void addMouseListener(OIS::MouseListener* mouseListener);
	void addJoyStickListener(OIS::JoyStickListener* joystickListener);
	// Remove listener
	void removeKeyListener(OIS::KeyListener* keyListener);
	void removeMouseListener(OIS::MouseListener* mouseListener);
	void removeJoyStickListener(OIS::JoyStickListener* joystickListener);
	// Remove all listener
	void removeAllListeners();
	void removeAllKeyListeners();
	void removeAllMouseListeners();
	void removeAllJoyStickListeners();
	// Singleton
	static OisFramework& getSingleton();
private:
	// Input Manager
	OIS::InputManager* mInputManager;
	// Keyboard and Mouse
	OIS::Keyboard* mKeyboard;
	OIS::Mouse* mMouse;
	std::vector<OIS::JoyStick*> mJoySticks;
	// External listeners
	std::vector<OIS::KeyListener*> mKeyListeners;
	std::vector<OIS::MouseListener*> mMouseListeners;
	std::vector<OIS::JoyStickListener*> mJoyStickListeners;
};

extern OisFramework& OisFrameworkSingleton;

#endif /* OISFRAMEWORK_HPP_ */
