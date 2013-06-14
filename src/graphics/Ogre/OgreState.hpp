/*
 * OgreState.hpp
 *
 *  Created on: 2013.04.20.
 *      Author: baarnus
 */

#ifndef OGRESTATE_HPP_
#define OGRESTATE_HPP_

#include "../../tools/app/structure/State.hpp"
#include "OgreFramework.hpp"
#include "../Ois/OisFramework.hpp"

class OgreState: public app::State, public Ogre::FrameListener
{
public:
	OgreState(Ogre::String name);
	virtual ~OgreState();
	// State activation
	virtual void onActivate();
	virtual void onDeactivate();

	void addCameraAndViewport(Ogre::Camera* camera, Ogre::Viewport* viewport);
	void createCameraAndViewport(int zOrder = 0, float left = 0.0f, float top = 0.0f, float width = 1.0f, float height = 1.0f);
	size_t getNumOfViews() const;
	Ogre::Camera* getCamera(size_t i);
	Ogre::Viewport* getViewport(size_t i);
protected:
	// State run
	void onRun();
	// OGRE
	Ogre::String mName;
	Ogre::SceneManager* mSceneManager;
	std::vector<std::pair<Ogre::Camera*, Ogre::Viewport*> > mViews;
};

#endif /* OGRESTATE_HPP_ */
