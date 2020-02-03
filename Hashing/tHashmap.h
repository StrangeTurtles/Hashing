#pragma once
template<typename K, typename V>
class tHashmap
{
	V * data;                       // buffer holding all potential pairs in the hashmap
	size_t dataCapacity;            // size of the above buffers

public:
	tHashmap();                     // constructs the hashmap with a specific size
	~tHashmap();                    // cleans-up any underlying data

	V& operator[] (const K& key);   // returns the object at the given key
};

