/*
 * ShipListController.cpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#include "ShipListController.hpp"
// Settings
#include "../../../game/settings/GameSettings.hpp"
// CEGUI
#include "../../../graphics/Cegui/CeguiTranslator.hpp"

//*****************************************************
//*** Ship List Controller Data Provider
//*****************************************************

ShipListControllerDataProvider::~ShipListControllerDataProvider()
{
}

//*****************************************************
//*** Ship List Controller
//*****************************************************

ShipListController::ShipListController() :
		mColumnList(NULL), mDataProvider(NULL)
{
}

ShipListController::~ShipListController()
{
}

CEGUI::MultiColumnList* ShipListController::getColumnList() const
{
	return mColumnList;
}

void ShipListController::setColumnList(CEGUI::MultiColumnList* columnList)
{
	mColumnList = columnList;
}

ShipListControllerDataProvider* ShipListController::getDataProvider() const
{
	return mDataProvider;
}

void ShipListController::setDataProvider(ShipListControllerDataProvider* dataProvider)
{
	mDataProvider = dataProvider;
}
// Build
void ShipListController::buildForSet()
{
	// If nil do nothing
	if (!mColumnList) return;
	// Clear
	clear();
	// Add columns
	mColumnList->addColumn(utf8ToCeguiString(GameSettingsSingleton.getLanguage().textForCode("game.ships.name")), 0, CEGUI::UDim(0.7, 0));
	mColumnList->addColumn(utf8ToCeguiString(GameSettingsSingleton.getLanguage().textForCode("game.ships.quantity")), 1, CEGUI::UDim(0.2, 0));
	// Add cells
	if (!mDataProvider) return;
	for (size_t i = 0; i < mDataProvider->numOfShipType(); ++i)
	{
		// Add row
		mColumnList->addRow(i);
		// Create cell for name
		CEGUI::ListboxTextItem* item;
		item = new CEGUI::ListboxTextItem(mDataProvider->getShipTypeName(i), i * 100 + 1);
		mColumnList->setItem(item, 0, i);
		// Create cell for count
		item = new CEGUI::ListboxTextItem(utf8ToCeguiString(utils::t2str(mDataProvider->getShipTypeCount(i))), i * 100 + 2);
		mColumnList->setItem(item, 1, i);
	}
}
void ShipListController::buildForBattle()
{
	// If nil do nothing
	if (!mColumnList) return;
	// Clear
	clear();
}
// Clear
void ShipListController::clear()
{
	// If nil do nothing
	if (!mColumnList) return;
	//
	for (unsigned i = 0; i < mColumnList->getColumnCount(); ++i)
	{
		// Remove Column
		mColumnList->removeColumnWithID(i);
	}
}
