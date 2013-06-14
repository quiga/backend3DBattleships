/*
 * resolution.hpp
 *
 *  Created on: 2013.06.12.
 *      Author: Baarnus
 */

#ifndef RESOLUTION_HPP_
#define RESOLUTION_HPP_

#include <utility>
#include <string>

namespace utils
{

std::pair<size_t, size_t> str2res(std::string resString);
std::string res2str(std::pair<size_t, size_t> res);
std::string res2str(size_t w, size_t h);
bool isResolution(std::string resString);

} /* Namespace utils */

#endif /* RESOLUTION_HPP_ */
