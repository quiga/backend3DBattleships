/*
 * stringconverters.hpp
 *
 *  Created on: 2013.01.23.
 *      Author: Baarnus
 */

#ifndef STRINGCONVERTERS_HPP_
#define STRINGCONVERTERS_HPP_

#include <string>
#include <sstream>

namespace utils
{

/**
 * Converts an UTF-8 encoded string to an UTF-32 encoded wstring
 * @param source An UTF-8 encoded string
 * @return An UTF-32 encoded wstring
 * @see wstringToUtf8()
 */
std::wstring utf8ToWString(std::string source);
/**
 * Converts an UTF-32 encoded wstring to an UTF-8 encoded string
 * @param source An UTF-32 encoded wstring
 * @return An UTF-8 encoded string
 * @see utf8ToWString()
 */
std::string wstringToUtf8(std::wstring source);
/**
 * Convert string to any given type
 * @param s the convertable string
 * @return the converted T type variable
 * @note Using sstream!
 * @see t2str()
 */
template<typename T>
T str2t(std::string s)
{
	std::stringstream ss(s);
	T value;
	ss >> value;
	return value;
}
/**
 * Convert any type to string
 * @param value the convertable T type variable
 * @return the converted string
 * @note Using sstream!
 * @see str2t()
 */
template<typename T>
std::string t2str(T value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

}
/* namespace utils */
#endif /* STRINGCONVERTERS_HPP_ */
