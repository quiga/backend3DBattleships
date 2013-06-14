/*
 * CeguiTranslator.hpp
 *
 *  Created on: 2013.06.13.
 *      Author: Baarnus
 */

#ifndef CEGUITRANSLATOR_HPP_
#define CEGUITRANSLATOR_HPP_

#include <CEGUI/CEGUI.h>
#include <string>

inline CEGUI::String utf8ToCeguiString(std::string utf8)
{
	return CEGUI::String((CEGUI::utf8*) utf8.c_str());
}

inline std::string ceguiStringToUtf8(CEGUI::String ceguiString)
{
	return ceguiString.c_str();
}

void translateCeguiWindow(CEGUI::Window* ceguiWindow, bool isRecursive = true);

#endif /* CEGUITRANSLATOR_HPP_ */
