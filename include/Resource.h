#ifndef __Resource__
#define __Resource__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <iostream>
#include <memory>

template<typename RESOURCE,typename IDENTIFIER = int>
class ResourceManager
{
	public:
		ResourceManager(const ResourceManager&) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;
		ResourceManager() = default;

		template<typename ... Args>
		void load(const IDENTIFIER& id,Args&& ... args);
		RESOURCE& get(const IDENTIFIER& id)const;

		private:
			std::unordered_map<IDENTIFIER,std::unique_ptr<RESOURCE>> _map;
};

#include "Resource.inl"

#endif