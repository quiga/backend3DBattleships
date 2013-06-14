/*
 * ResourceStore.tpp
 *
 *  Created on: 2013.01.24.
 *      Author: Baarnus
 */

#include "ResourceStore.hpp"

template<typename R>
ResourceStore<R>::ResourceStore()
{
}

template<typename R>
ResourceStore<R>::~ResourceStore()
{
	clear();
}

template<typename R>
std::string ResourceStore<R>::getDirectory() const
{
	return m_folder;
}

template<typename R>
void ResourceStore<R>::setDirectory(const std::string folder)
{
	m_folder = folder;
}

template<typename R>
std::string ResourceStore<R>::pathForResource(std::string resourcePath) const
{
	return m_folder + (m_folder.length() == 0 ? "" : "/") + resourcePath;
}

template<typename R>
std::wstring ResourceStore<R>::wpathForResource(std::string resourcePath) const
{
	return utf8ToWString(pathForResource(resourcePath));
}

template<typename R>
typename ResourceStore<R>::ResourcePtr ResourceStore<R>::get(std::string resourcePath)
{
	// Get
	auto findIt = m_store.find(resourcePath);
	if (findIt != m_store.end()) return findIt->second;
	// Insert - if isn't exist
	ResourcePtr new_res = loadResource(pathForResource(resourcePath));
	if (new_res) m_store.insert(std::pair<std::string, ResourcePtr>(resourcePath, new_res));
	return new_res;
}

template<typename R>
void ResourceStore<R>::remove(std::string name)
{
	auto eraseIt = m_store.find(name);
	if (eraseIt != m_store.end()) m_store.erase(eraseIt);
}

template<typename R>
void ResourceStore<R>::clear()
{
}
