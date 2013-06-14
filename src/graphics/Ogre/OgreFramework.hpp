/*
 * OgreFramework.hpp
 *
 *  Created on: 2013.06.12.
 *      Author: Baarnus
 */

#ifndef OGREFRAMEWORK_HPP_
#define OGREFRAMEWORK_HPP_

// STD
#include <utility>
// OGRE
#include <OGRE/Ogre.h>

class OgreFrameworkInitHelper
{
public:
	virtual ~OgreFrameworkInitHelper();
	// Configs
	virtual Ogre::String getPluginsCfg();
	virtual Ogre::String getResourcesCfg();
	// Log
	virtual Ogre::String getOgreLog();
	// Graphics metrics
	virtual std::pair<int, int> getResolution();
	virtual bool isFullscreen();
	virtual Ogre::String getWindowTitle();
};

class OgreFramework
{
public:
	// Create/Destroy
	OgreFramework();
	virtual ~OgreFramework();
	// Init
	void init(OgreFrameworkInitHelper* initHelper = NULL);
	// Shut down
	void shutdown();
	// Get objects
	Ogre::Root* getRoot();
	Ogre::RenderSystem* getRenderSystem();
	Ogre::RenderWindow* getRenderWindow();
	// Control
	void toggleFullscreen();
	// Singleton
	static OgreFramework& getSingleton();
private:
	Ogre::Root* mRoot;
	Ogre::RenderSystem* mRenderSystem;
	Ogre::RenderWindow* mRenderWindow;
};

extern OgreFramework& OgreFrameworkSingleton;

#endif /* OGREFRAMEWORK_HPP_ */
