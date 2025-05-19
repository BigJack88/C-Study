#include "Singleton.h"

int main()
{
	auto singleA = SingleNet::GetInst();
	std::cout << singleA << std::endl;
	auto singleB = SingleNet::GetInst();
	std::cout << singleB << std::endl;
	return 0;
}