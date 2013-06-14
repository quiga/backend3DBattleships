/*
 * CeguiFramework.hpp
 *
 *  Created on: 2013.06.12.
 *      Author: Baarnus
 */

#ifndef CEGUIFRAMEWORK_HPP_
#define CEGUIFRAMEWORK_HPP_

#include <CEGUI/CEGUI.h>

class CeguiFrameworkInitHelper
{
public:
	virtual ~CeguiFrameworkInitHelper();
	virtual void bootstrapRenderer() = 0;
	virtual CEGUI::String getCeguiLog();
};

class CeguiFramework
{
public:
	// Create/Destroy
	CeguiFramework();
	virtual ~CeguiFramework();
	// Init
	void init(CeguiFrameworkInitHelper* initHelper);
	// Shut down
	void shutdown();
	// Singleton
	static CeguiFramework& getSingleton();
private:
	bool mIsInited;
};

extern CeguiFramework& CeguiFrameworkSingleton;

#endif /* CEGUIFRAMEWORK_HPP_ */
