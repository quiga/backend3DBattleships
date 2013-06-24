/*
 * field.h
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#ifndef FIELD_H_
#define FIELD_H_
#include "Ship.h"

namespace AstrOWar {

class field {
private:
	Ship *hajo;
	bool isDisruptive;	// felrobbantott-e
	int posX;
	int posY;
	int posZ;

public:
	field(int x, int y, int z);
	virtual ~field();

	void setShip(Ship *s);
	void setHajo(Ship *hajo);
	void setDisruptive(bool isDisruptive);

	Ship* getHajo();
	int getPosX() const;
	int getPosY() const;
	int getPosZ() const;

	bool IsDisruptive() const;

	std::string toString();
};

} /* namespace AstrOWar */
#endif /* FIELD_H_ */
