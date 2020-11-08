#include <iostream>
#include "dict.h"
int main()
{
	Dict dict1;
	dict1.add("One", 1);
	dict1.add("Two", 2);
	dict1.add("Three", 3);
	std::cout << "Hello" << std::endl;
	std::cout << dict1.get("One") << dict1.get("Two") << dict1.get("Three") << std::endl;
}