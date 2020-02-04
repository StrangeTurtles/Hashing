#pragma once
#include "hash.h"
template<typename K, typename V>
class tHashmap
{
	V * data;                       // buffer holding all potential pairs in the hashmap
	size_t dataCapacity;            // size of the above buffers

public:
	tHashmap();                     // constructs the hashmap with a specific size
	~tHashmap();                    // cleans-up any underlying data


	V& operator= (const tHashmap& other);

	V& operator[] (const K& key);   // returns the object at the given key
};

template<typename K, typename V>
tHashmap<K, V>::tHashmap()
{
	dataCapacity = 15;
	data = new V[dataCapacity];
}

template<typename K, typename V>
tHashmap<K, V>::~tHashmap()
{
	delete(data);
	delete(dataCapacity);
}

template<typename K, typename V>
inline V & tHashmap<K, V>::operator=(const tHashmap & other)
{
	// TODO: insert return statement here
}

template<typename K, typename V>
V & tHashmap<K, V>::operator[](const K & key)
{
	auto hashedKey = hash(key) % dataCapacity;
	return data[hashedKey];
}