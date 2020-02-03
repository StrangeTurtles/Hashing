#pragma once
#include <limits>
#include <string>

// template declaration for hash
template<typename T>
size_t hash(const T& val)
{
	// unelegant way of telling users to specialize this template
	T::please_specialize_this_template_for_your_type;
}

// template specialization for int
template<>
size_t hash<int>(const int& val)
{
	// Knuth's hash function
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}

// template specialization for char
template<>
size_t hash<char>(const char& val)
{
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}

//template specialization for C-strings
template<>
size_t hash<char*>(char * const & val)
{
	int count = 0;
	int hash = 0;
	while (val[count] != '/0')
	{
		(int)val[count];
		count++;
	}
	return hash * 2654435761 % std::numeric_limits<size_t>::max();
}

// template specialization for std::string
template<>
size_t hash<std::string>(const std::string& val)
{
	int count = 0;
	int hash = 0;
	while (val[count] != '/0')
	{
		(int)val[count];
		count++;
	}
	return hash * 2654435761 % std::numeric_limits<size_t>::max();
}