/*
 * Language.hpp
 *
 *  Created on: 2013.01.23.
 *      Author: Baarnus
 */

#ifndef LANGUAGE_T_HPP_
#define LANGUAGE_T_HPP_

#include <memory>
#include <string>
#include <map>
#include <list>

namespace app
{

// Store for string in a language
class Language
{
public:
	// Load texts from a csv file
	bool loadFromFile(std::string filename);
	// Load texts from a csv formatted string
	bool loadFromString(std::string content);
	// Get a text to a code
	std::string textForCode(std::string code) const;
	// Get a wtext to a code
	std::wstring wtextForCode(std::string code) const;
	// Get lists of languages
	const std::list<std::pair<std::string, std::string> > getLanguageList() const;
	// Check if there is translation for lang code
	bool isTranslationExtist(std::string code) const;
	// Get the name of the translation
	std::string getLangName(std::string code) const;

	// Setter for LangCode
	std::string getActLangCode() const;
	void setLangCode(const std::string actLangCode);

	// Pointer type
	typedef std::shared_ptr<Language> Ptr;
private:
	// The dictionary string -> string
	std::map<std::string, std::string> m_dictionary;
	// The language list
	std::list<std::pair<std::string, std::string> > m_languages;
	// The actual language code
	std::string m_actLangCode = "en";
};

} /* namespace app */
#endif /* LANGUAGE_T_HPP_ */
