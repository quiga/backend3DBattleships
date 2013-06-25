/*
 * message.cpp
 *
 *  Created on: 2013.06.25.
 *      Author: quiga
 */

#include "message.h"

namespace AstrOWar {

message::message() :
		msgType(0), posX(0), posY(0), posZ(0), id(0), refId(0) {
}

message::~message() {
}
void message::init(int _msgType, int _posX, int _posY, int _posZ, int _id, int _refId) {
	msgType = _msgType;
	posX = _posX;
	posY = _posY;
	posZ = _posZ;
	id = _id;
	refId = _refId;
}

message message::init(int _msgType, int _id, int _refId) {
	msgType = _msgType;
	posX = posY = posZ = 0;
	id = _id;
	refId = _refId;
	return (*this);
}

int message::getMsgType() {
	return msgType;
}

int message::getPosX() {
	return posX;
}

int message::getPosY() {
	return posY;
}

int message::getPosZ() {
	return posZ;
}

int message::getId() {
	return id;
}

int message::getRefId() {
	return refId;
}


} /* namespace AstrOWar */
