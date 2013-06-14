/*
 * GameSettings.h
 *
 *  Created on: 2013.06.11.
 *      Author: Baarnus
 */

#ifndef GAMESETTINGS_H_
#define GAMESETTINGS_H_

#include "../../tools/utils.hpp"
#include "../../tools/language.hpp"
#include "../../tools/app/settings/subsettings/GeneralSubSettings.hpp"
#include "../../graphics/utils/GraphicsSubSettings.hpp"

class GameSettings
{
public:
	GameSettings();
	virtual ~GameSettings();
	// Init
	void init(int argc, char** argv, std::string iniFile, std::string langFile);
	// Get subsettings
	app::Language& getLanguage();
	app::GeneralSubSettings& getGeneralSettings();
	grapp::GraphicsSubSettings& getGraphicsSettings();
	// Singleton
	static GameSettings& getSingleton();
private:
	app::Settings mSettings;
	app::Language mLanguage;
	app::GeneralSubSettings* mGeneralSettings;
	grapp::GraphicsSubSettings* mGraphicsSettings;
};

extern GameSettings& GameSettingsSingleton;

#endif /* GAMESETTINGS_H_ */
