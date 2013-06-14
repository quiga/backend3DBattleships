/*
 * HelloWorldSubSetting.cpp
 *
 *  Created on: 2013.06.11.
 *      Author: Baarnus
 */

#include "GeneralSubSettings.hpp"

namespace app
{

GeneralSubSettings::GeneralSubSettings()
{
}

GeneralSubSettings::~GeneralSubSettings()
{
}

bool GeneralSubSettings::isHelloWorld() const
{
	return isOption("helloworld");
}

std::string GeneralSubSettings::getLangCode() const
{
	return getOption<std::string>("main.lang");
}

void GeneralSubSettings::setLangCode(const std::string langCode)
{
	setOption<std::string>("main.lang", langCode);
}

void GeneralSubSettings::onInit()
{
	addOption("helloworld", "'Hello world!' easter egg. :)");
	addOption<std::string>("main.lang", "Language of the application", "en");
}

} /* namespace app */
