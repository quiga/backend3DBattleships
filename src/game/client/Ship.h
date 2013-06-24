/*
 * Ship.h
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#ifndef SHIP_H_
#define SHIP_H_
#include <vector>
#include <string>
#include <iostream>
using namespace std;

namespace AstrOWar {
class field;

class Ship {
protected:
	std::string name;
	int x, y, z;		// mátrix segédek
	std::string mesh;
	std::vector<std::vector<int> > structure;
	std::vector<field*> mezok;
	Ship* _clone(Ship *s);

public:
	Ship();
	virtual ~Ship();

	void setName(std::string str);
	void setX(int i);
	void setY(int i);
	void setZ(int i);
	void setMesh(std::string str);
	void setStructure(vector<vector<int> > v);
	void addField(field* f);

	vector<vector<int> > getStructure();
	std::string getName();
	std::string getMesh();
	int getX();
	int getY();
	int getZ();
	bool isNew();

	Ship* clone();
	void toString();
};

} /* namespace AstrOWar */
#endif /* SHIP_H_ */
