#include "tHashmap.h"


template<typename K, typename V>
tHashmap<K, V>::tHashmap()
{
	dataCapacity = 15;
	data = new V[dataCapacity];
}

template<typename K, typename V>
tHashmap<K, V>::~tHashmap()
{
}

template<typename K, typename V>
V & tHashmap<K, V>::operator[](const K & key)
{
	auto hashedKey = hash(key) % dataCapacity; 
	return data[hashedKey];
}
