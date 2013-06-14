/*
 * stringalgorithms.hpp
 *
 *  Created on: 2013.01.26.
 *      Author: Baarnus
 */

#ifndef STRINGALGORITHMS_HPP_
#define STRINGALGORITHMS_HPP_

#include <vector>
#include <string>

namespace utils
{

/**
 * Split string to substrings by delimiter
 * @param source the splitable string
 * @param delimiter the cut delimiter
 * @param bTokenCompress need to be the tokens compressed
 * @param bFilterEmpty need to filter the empty substrings from the result
 * @return vector of substrings
 */
std::vector<std::string> split(std::string source, std::string delimiter, bool bTokenCompress = false, bool bFilterEmpty = false);

} /* namespace utils */
#endif /* STRINGALGORITHMS_HPP_ */
