/*
 * ShipListController.hpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#ifndef SHIPLISTCONTROLLER_HPP_
#define SHIPLISTCONTROLLER_HPP_

// CEGUI
#include <CEGUI/CEGUI.h>

class ShipListControllerDataProvider
{
public:
	virtual ~ShipListControllerDataProvider();
	// Data
	virtual size_t numOfShipType() = 0;
	virtual CEGUI::String getShipTypeName(size_t i) = 0;
	virtual size_t getShipTypeCount(size_t i) = 0;
};

class ShipListController
{
public:
	// Create/Destroy
	ShipListController();
	virtual ~ShipListController();
	// Setter / Getter
	CEGUI::MultiColumnList* getColumnList() const;
	void setColumnList(CEGUI::MultiColumnList* columnList);
	ShipListControllerDataProvider* getDataProvider() const;
	void setDataProvider(ShipListControllerDataProvider* dataProvider);
	// Build
	void buildForSet();
	void buildForBattle();
	// Clear
	void clear();
private:
	// Controllable element
	CEGUI::MultiColumnList* mColumnList;
	// Data provider
	ShipListControllerDataProvider* mDataProvider;
};

#endif /* SHIPLISTCONTROLLER_HPP_ */
