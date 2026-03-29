#include "rational.h"
#include <iostream>

int main(void)
{
	rational<int> r1(3,1);
	rational<int> r2(-7,0);
	rational<int> r = r1+r2;
	std::cout << r << "\n";
	return 0;
}