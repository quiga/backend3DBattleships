/*
 * AstrOWarShipListDataProvider.cpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#include "AstrOWarShipListDataProvider.hpp"
// CEGUI
#include "../../../graphics/Cegui/CeguiTranslator.hpp"

AstrOWarShipListDataProvider::AstrOWarShipListDataProvider()
{
}

AstrOWarShipListDataProvider::~AstrOWarShipListDataProvider()
{
}

// Ship list data provider
size_t AstrOWarShipListDataProvider::numOfShipType()
{
	return 3;
}

CEGUI::String AstrOWarShipListDataProvider::getShipTypeName(size_t i)
{
	return CEGUI::String(utf8ToCeguiString("Bééla"));
}

size_t AstrOWarShipListDataProvider::getShipTypeCount(size_t i)
{
	return (i + 2) * 3 - 4;
}
