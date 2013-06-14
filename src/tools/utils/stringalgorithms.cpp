/*
 * stringalgorithms.cpp
 *
 *  Created on: 2013.01.26.
 *      Author: Baarnus
 */

#include "stringalgorithms.hpp"

#include <boost/algorithm/string.hpp>

using namespace std;

namespace utils
{

std::vector<std::string> split(std::string source, std::string delimiter, bool bTokenCompress, bool bFilterEmpty)
{
	vector<string> result;
	// Split with boost
	boost::split(result, source, boost::is_any_of(delimiter), (bTokenCompress ? boost::token_compress_on : boost::token_compress_off));
	// If filter:
	if (bFilterEmpty)
	{
		vector<string> tmp;
		for (auto it = result.begin(); it != result.end(); ++it)
		{
			if ((*it).length() > 0)
			{
				tmp.push_back(*it);
			}
		}
		result = tmp;
	}
	return result;
}

} /* namespace utils */
