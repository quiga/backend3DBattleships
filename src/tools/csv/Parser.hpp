/*
 * CsvParser.hpp
 *
 *  Created on: 2012.12.02.
 *      Author: Baarnus
 */

#ifndef CSVPARSER_HPP_
#define CSVPARSER_HPP_

#include <memory>
#include <string>

// namespace for csv handlers
namespace csv
{

// Parser delegate recieve the informations during the process
class ParseDelegate
{
public:
	// Using with smart pointers
	typedef std::shared_ptr<ParseDelegate> Ptr;
	// Handler functions:
	// Run once at the begining of the process
	virtual void onStartDocument(std::string title) = 0;
	// Run on every line start
	virtual void onStartLine(int lineNumber) = 0;
	// Run on every cell
	virtual void onReadField(std::string field, int fieldNumber) = 0;
	// Run on every line end
	virtual void onEndLine(int lineNumber) = 0;
	// Run once at the end of the process
	virtual void onEndDocument(std::string title) = 0;
	// Virtual destructor
	virtual ~ParseDelegate();
};

bool parseFile(std::string filename, ParseDelegate::Ptr pDelegate, char p_delimiter);
bool parseString(std::string content, ParseDelegate::Ptr pDdelegate, char p_delimiter);

}       // namespace csv

#endif /* CSVPARSER_HPP_ */
