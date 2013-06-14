/*
 * Settings.cpp
 *
 *  Created on: 2013.01.23.
 *      Author: Baarnus
 */

#include "Settings.hpp"

#include <fstream>
#include <iostream>

using namespace std;
using namespace boost::program_options;

namespace app
{

Settings::SubSettings::~SubSettings()
{
}

void Settings::SubSettings::addOption(std::string name, std::string description)
{
	mSettings->addOption(name, description);
}

bool Settings::SubSettings::isOption(std::string name) const
{
	return mSettings->isOption(name);
}

Settings::Settings()
{
}

Settings::~Settings()
{
	for (auto ssp : mSubSettings)
		delete ssp;
}

// Loaders
void Settings::loadFromFile(std::string filename)
{
	ifstream fin(filename.c_str());
	if (fin.is_open())
	{
		try
		{
			store(parse_config_file(fin, m_settingsDescription, true), m_settingsMap, true);
			notify(m_settingsMap);
		}
		catch (boost::exception &e)
		{
			cout << "Wrong options in the ini file! The candidates are:" << endl;
			cout << m_settingsDescription << endl;
		}
	}
}

void Settings::loadFromArgs(int argc, char** argv)
{
	try
	{
		store(parse_command_line(argc, argv, m_settingsDescription), m_settingsMap);
	}
	catch (boost::exception &e)
	{
		cout << "Wrong options! The candidates are:" << endl;
		cout << m_settingsDescription << endl;
	}
	notify(m_settingsMap);
}

void Settings::addOption(std::string name, std::string description)
{
	m_settingsDescription.add_options()(name.c_str(), description.c_str());
}

bool Settings::isOption(std::string name) const
{
	return m_settingsMap.count(name);
}

Settings::Ptr Settings::getMainOptions()
{
	static Ptr instance(new Settings);
	return instance;
}

} /* namespace app */
