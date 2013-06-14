/*
 * GraphicsSubSettings.h
 *
 *  Created on: 2013.06.11.
 *      Author: Baarnus
 */

#ifndef GRAPHICSSUBSETTINGS_H_
#define GRAPHICSSUBSETTINGS_H_

#include "../../tools/app/settings/Settings.hpp"
// STD
#include <utility>

namespace grapp
{

class GraphicsSubSettings: public app::Settings::SubSettings
{
public:
	GraphicsSubSettings();
	virtual ~GraphicsSubSettings();
	// Resolution
	typedef std::pair<int, int> ResolutionType;
	ResolutionType getResolution() const;
	void setResolution(const ResolutionType resolution);
	void setResolution(int width, int height);
	// Fullscreen
	bool isFullscreen() const;
	void setFullscreen(const bool fullscreen);
protected:
	void onInit();
};

} /* namespace grapp */
#endif /* GRAPHICSSUBSETTINGS_H_ */
