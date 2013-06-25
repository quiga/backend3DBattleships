/*
 * message.h
 *
 *  Created on: 2013.06.25.
 *      Author: quiga
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

namespace AstrOWar {


/*
 * id: csomag azonosítója, a szerver a csatlakozás után küld a kliensnek egy üzenetet 1-es id-val
 * refId: ha a csomag egy másik csomag válasza, egyébként 0
 * msgType: csomag tipusa, ez lehet:
 * 			- 1 : HELLO
 * 			- 2 : OK
 * 			- 3 : BAD
 * 			- 4 : FIRE
 * 			- 5 : IMDIED
 * 			- 6 : FIREOK
 * 			- 7 : FIREBAD
 * 			- 8 : EXIT
 * 			ha 0, akkor a csomag hibás
 * pos: koordináták, X,Y,Z, default érték: 0
 */

class message {
	int msgType;
	int posX;
	int posY;
	int posZ;
	int id;
	int refId;

public:
	message();
	virtual ~message();
	void init(int _msgType, int _posX, int _posY, int _posZ, int _id, int _refId);
	message init(int _msgType, int _id, int _refId);

	int getMsgType();
	int getPosX();
	int getPosY();
	int getPosZ();
	int getId();
	int getRefId();
	bool validate(){return msgType != 0;}
};

} /* namespace AstrOWar */
#endif /* MESSAGE_H_ */
