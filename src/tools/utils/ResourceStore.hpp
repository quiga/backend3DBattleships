/*
 * ResourceStore.hpp
 *
 *  Created on: 2013.01.24.
 *      Author: Baarnus
 */

#ifndef RESOURCESTORE_HPP_
#define RESOURCESTORE_HPP_

#include <map>
#include <string>
#include <memory>

#include "stringconverters.hpp"

namespace utils
{

/**
 * Usable for resource load and store
 * Store the source folder where resource is hold
 *
 * @note the 'loadResource' must be template specialised!
 */
template<typename R>
class ResourceStore
{
public:
	/**
	 * Default constructor of the resource store.
	 */
	ResourceStore();
	/**
	 * Default destructor of the resource store.
	 * @note Destroys all the stored resources.
	 */
	virtual ~ResourceStore();
	/**
	 * Get the corresponding source directory.
	 * @return The source directory.
	 */
	std::string getDirectory() const;
	/**
	 * Set the corresponding source directory.
	 * @param 'folderPath' path to the source directory.
	 */
	void setDirectory(const std::string folderPath);
	/**
	 * Generate the full path for a given resource.
	 * Using the setted source directory.
	 * @param 'resourcePath' resource path relative to the setted source directory.
	 * @return Full path to the resource.
	 * @see wpathForResource()
	 */
	std::string pathForResource(std::string resourcePath) const;
	/**
	 * Generate the full path for a given resource.
	 * Using the setted source directory
	 * @param resourcePath resource path relative to the setted source directory
	 * @return Full path to the resource
	 * @see pathForResource()
	 */
	std::wstring wpathForResource(std::string resourcePath) const;
	/**
	 * Shared pointer type for stored R-type resource
	 */
	typedef std::shared_ptr<R> ResourcePtr;
	/**
	 * Get a resource by name.
	 * @note This function loads the resource if it isn't loaded.
	 * @param 'name' relative path of the resource to the source directory.
	 * @return Shared pointer to the resource.
	 */
	ResourcePtr get(std::string name);
	/**
	 * Remove a loaded resource by name.
	 * @param 'name' relative path of the resource to the source directory.
	 * @note If the resource doesn't exist, this function does nothing.
	 * @see remove()
	 * @see clear()
	 */
	void remove(std::string name);
	/**
	 * Remove all the loaded resources.
	 * @see get()
	 * @see remove()
	 */
	void clear();
protected:
	/**
	 * Source directory path
	 */
	std::string m_folder;
	/**
	 * Stored resources
	 */
	std::map<std::string, ResourcePtr> m_store;
	/**
	 * Load the resource
	 * @note Must be template specialised for the usable resource type!
	 */
	virtual ResourcePtr loadResource(std::string resourcePath);
};

#include "ResourceStore.tpp"

} /* namespace utils */
#endif /* RESOURCESTORE_HPP_ */
