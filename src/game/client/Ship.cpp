/*
 * Ship.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "Ship.h"

namespace AstrOWar {

Ship::Ship() {
	x = y = z = 0;
}

Ship* Ship::_clone(Ship *s) {
	setName(s->getName());
	setX(s->getX());
	setY(s->getY());
	setZ(s->getZ());
	setMesh(s->getMesh());
	setStructure(s->getStructure());
	return this;
}

Ship::~Ship() {
}

void Ship::setName(std::string str) {
	name = str;
}
void Ship::setX(int i) {
	x = i;
}
void Ship::setY(int i) {
	y = i;
}
void Ship::setZ(int i) {
	z = i;
}
void Ship::setMesh(std::string str) {
	mesh = str;
}

void Ship::setStructure(vector<vector<int> > v) {
	structure = v;
}

Ship* Ship::clone() {
	return (new Ship())->_clone(this);
}

vector<vector<int> > Ship::getStructure() {
	return structure;
}
std::string Ship::getName() {
	return name;
}
int Ship::getX() {
	return x;
}
int Ship::getY() {
	return y;
}
int Ship::getZ() {
	return z;
}
std::string Ship::getMesh() {
	return mesh;
}

void Ship::toString() {
	cout << name << endl;
	for (unsigned int i = 0; i < structure.size(); i++) {
		for (unsigned int j = 0; j < structure[i].size(); j++)
			cout << structure[i][j] << " ";
		cout << endl;
	}
}

void Ship::addField(field* f) {
	mezok.push_back(f);
}

bool Ship::isNew() {
	return mezok.size() == 0;
}
} /* namespace AstrOWar */
