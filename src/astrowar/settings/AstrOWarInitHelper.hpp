/*
 * AstrOWarOgreInitHelper.hpp
 *
 *  Created on: 2013.06.12.
 *      Author: Baarnus
 */

#ifndef ASTROWAROGREINITHELPER_HPP_
#define ASTROWAROGREINITHELPER_HPP_

#include "../../graphics/Ogre/OgreFramework.hpp"
#include "../../graphics/Ois/OisFramework.hpp"
#include "../../graphics/Cegui/CeguiFramework.hpp"

class AstrOWarInitHelper: public OgreFrameworkInitHelper, public OisFrameworkInitHelper, public CeguiFrameworkInitHelper
{
public:
	AstrOWarInitHelper();
	virtual ~AstrOWarInitHelper();

	// Configs
	virtual Ogre::String getPluginsCfg();
	virtual Ogre::String getResourcesCfg();
	// Ogre Log
	virtual Ogre::String getOgreLog();
	// Graphics metrics
	virtual std::pair<int, int> getResolution();
	virtual bool isFullscreen();
	virtual Ogre::String getWindowTitle();
	// Window handler OIS
	virtual unsigned getWindowHnd();
	// Cegui bootsrap
	virtual void bootstrapRenderer();
	// Cegui log
	virtual CEGUI::String getCeguiLog();
};

#endif /* ASTROWAROGREINITHELPER_HPP_ */
