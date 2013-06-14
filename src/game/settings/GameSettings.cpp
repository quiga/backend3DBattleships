/*
 * GameSettings.cpp
 *
 *  Created on: 2013.06.11.
 *      Author: Baarnus
 */

#include "GameSettings.hpp"

GameSettings::GameSettings()
{
	mGeneralSettings = mSettings.createSubSetting<app::GeneralSubSettings>();
	mGraphicsSettings = mSettings.createSubSetting<grapp::GraphicsSubSettings>();
}

GameSettings::~GameSettings()
{
}

void GameSettings::init(int argc, char** argv, std::string iniFile, std::string langFile)
{
	mSettings.loadFromFile(iniFile);
	mSettings.loadFromArgs(argc, argv);
	mLanguage.setLangCode(mGeneralSettings->getLangCode());
	mLanguage.loadFromFile(langFile);
}

app::Language& GameSettings::getLanguage()
{
	return mLanguage;
}

app::GeneralSubSettings& GameSettings::getGeneralSettings()
{
	return *mGeneralSettings;
}

grapp::GraphicsSubSettings& GameSettings::getGraphicsSettings()
{
	return *mGraphicsSettings;
}

GameSettings& GameSettings::getSingleton()
{
	static GameSettings instance;
	return instance;
}

GameSettings& GameSettingsSingleton = GameSettings::getSingleton();
