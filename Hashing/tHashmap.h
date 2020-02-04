#pragma once
#include "hash.h"
template<typename K, typename V>
class tHashmap
{
	V * data;                       // buffer holding all potential pairs in the hashmap
	size_t dataCapacity;            // size of the above buffers

public:
	tHashmap();                     // constructs the hashmap with a specific size
	tHashmap(int amount);
	~tHashmap();                    // cleans-up any underlying data

	tHashmap(const tHashmap& other);

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
inline tHashmap<K, V>::tHashmap(int amount)
{
	dataCapacity = amount;
	data = new V[dataCapacity];
}

template<typename K, typename V>
tHashmap<K, V>::~tHashmap()
{
	dataCapacity = 0;
	data = 0;
}

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap(const tHashmap & other)
{
	data = new V[other.dataCapacity];
	dataCapacity = other.dataCapacity;
	for (int i = 0; i < dataCapacity; i++)
	{
		data[i] = other.data[i];
	}
}

//if the data capacity is the same then copy the data to the lhs
template<typename K, typename V>
inline V & tHashmap<K, V>::operator=(const tHashmap & rhs)
{
	// TODO: insert return statement here
	if (dataCapacity == rhs.dataCapacity)
	{
		for (int i = 0; i < dataCapacity; i++)
		{
			data[i] = rhs.data[i];
		}
	}
}

template<typename K, typename V>
V & tHashmap<K, V>::operator[](const K & key)
{
	auto hashedKey = hash(key) % dataCapacity;
	return data[hashedKey];
}
