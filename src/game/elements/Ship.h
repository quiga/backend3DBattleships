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

/*
 * a hajó akkor robban fel, ha a mezőinek legalább X százalékát eltalálták.
 */

#define X 0.4

namespace AstrOWar {
class Field;

class Ship {
protected:
	std::string name;
	int x, y, z;		// mátrix segédek
	std::string mesh;
	std::vector<std::vector<int> > structure;
	std::vector<Field*> mezok;
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
	void addField(Field* f);

	vector<vector<int> > getStructure();
	std::string getName();
	std::string getMesh();
	int getX();
	int getY();
	int getZ();
	bool isNew();
	bool isDead();

	Ship* clone();
	void toString();
};

} /* namespace AstrOWar */
#endif /* SHIP_H_ */