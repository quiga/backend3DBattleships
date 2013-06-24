/*
 * field.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "field.h"

namespace AstrOWar {

field::field(int x, int y, int z) {
	posX = x;
	posY = y;
	posZ = z;
	isDisruptive = false;
	hajo = nullptr;
}

field::~field() {
}

void field::setShip(Ship *s) {
	hajo = s;
}

std::string field::toString() {
	return (hajo == nullptr) ? "0" : "1";
}

Ship* field::getHajo() {
	return hajo;
}

void field::setHajo(Ship* hajo) {
	this->hajo = hajo;
}

bool field::IsDisruptive() const {
	return isDisruptive;
}

void field::setDisruptive(bool isDisruptive) {
	this->isDisruptive = isDisruptive;
}

int field::getPosX() const {
	return posX;
}

int field::getPosY() const {
	return posY;
}

int field::getPosZ() const {
	return posZ;
}

} /* namespace AstrOWar */
