/*
 * Parser.h
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#ifndef PARSER_H_
#define PARSER_H_
#include "jansson.h"
#include "../../game/client/Ship.h"
#include <string>
#include <vector>

namespace JSON {

class Parser {
private:
	json_error_t error;
	json_t *root;
protected:
	Parser();
	virtual ~Parser();
	int parseShip(std::string path, AstrOWar::Ship &h);
public:
	int parse(std::string path, std::vector<AstrOWar::Ship> *ships);
	void decode(std::string json);
	void encode(std::string json);
	static Parser& getSingleton();
};
extern Parser& JSONSingleton;
} /* namespace JSON */
#endif /* PARSER_H_ */
