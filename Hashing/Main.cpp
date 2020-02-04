#include <iostream>
#include "tHashmap.h"
#include "hash.h"

int main()
{
	tHashmap<std::string, int> favoriteNumbersByName;
	favoriteNumbersByName["Terry"] = 5;

	tHashmap<std::string, int> favoriteNumbersByNameCpy(favoriteNumbersByName);

	std::cout << favoriteNumbersByName["Terry"] << std::endl; // 5
	std::cout << favoriteNumbersByNameCpy["Terry"] << std::endl; // 5

	tHashmap<std::string, int> testWord;
	testWord["Robert"] = 13;

	testWord["Jon"] = 3;

	std::cout << testWord["Robert"] << std::endl; // 13
	std::cout << testWord["Jon"] << std::endl; // 3

	while (true)
	{

	}
}