#include <iostream>
#include "Split.hpp"

#define TEST "    The  quick  brown     fox   a b c d e f g h i j k l                      "
int main(void)
{
	Split s;
	size_t i;

	std::cout << TEST << std::endl;
	s.split(TEST, ' ');
	for (i = 0; i < s.size(); i++)
		std::cout << s[i] << std::endl;
	std::cout << s.join(' ') << std::endl;
	return (0);
}
