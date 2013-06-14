/*
 * resolution.cpp
 *
 *  Created on: 2013.06.12.
 *      Author: Baarnus
 */

#include "resolution.hpp"
// BOOST
#include <boost/regex.hpp>
// UTILS
#include "../../tools/utils.hpp"

namespace utils
{

std::pair<size_t, size_t> str2res(std::string resString)
{
	auto xPos = resString.find('x');
	size_t x = utils::str2t<size_t>(resString.substr(0, xPos));
	size_t y = utils::str2t<size_t>(resString.substr(xPos + 1, resString.length() - xPos));
	return std::make_pair(x, y);
}
std::string res2str(std::pair<size_t, size_t> res)
{
	return t2str(res.first) + "x" + t2str(res.second);
}
std::string res2str(size_t w, size_t h)
{
	return t2str(w) + "x" + t2str(h);
}
bool isResolution(std::string resString)
{
	boost::regex resRegex(" *[0-9]+ *x *[0-9]+ *");
	return boost::regex_match(resString, resRegex);
}

} /* Namespace utils */
