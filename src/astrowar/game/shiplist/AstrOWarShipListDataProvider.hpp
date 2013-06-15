/*
 * AstrOWarShipListDataProvider.hpp
 *
 *  Created on: 2013.06.15.
 *      Author: Baarnus
 */

#ifndef ASTROWARSHIPLISTDATAPROVIDER_HPP_
#define ASTROWARSHIPLISTDATAPROVIDER_HPP_

#include "ShipListController.hpp"

class AstrOWarShipListDataProvider: public ShipListControllerDataProvider
{
public:
	AstrOWarShipListDataProvider();
	virtual ~AstrOWarShipListDataProvider();
	// Ship list data provider
	virtual size_t numOfShipType();
	virtual CEGUI::String getShipTypeName(size_t i);
	virtual size_t getShipTypeCount(size_t i);
};

#endif /* ASTROWARSHIPLISTDATAPROVIDER_HPP_ */
