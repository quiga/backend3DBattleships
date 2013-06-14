/*
 * HelloWorldSubSetting.h
 *
 *  Created on: 2013.06.11.
 *      Author: Baarnus
 */

#ifndef HELLOWORLDSUBSETTING_H_
#define HELLOWORLDSUBSETTING_H_

#include "../Settings.hpp"

namespace app
{

class GeneralSubSettings: public app::Settings::SubSettings
{
public:
	GeneralSubSettings();
	virtual ~GeneralSubSettings();

	bool isHelloWorld() const;
	std::string getLangCode() const;
	void setLangCode(const std::string langCode);
protected:
	void onInit();
};

} /* namespace app */
#endif /* HELLOWORLDSUBSETTING_H_ */
