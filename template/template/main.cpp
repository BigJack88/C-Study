#include "template.h"
#include <vector>
#include <list>
int main()
{
	int a = 10;
	double b = 2.11;
	const char* cString = "fuck you";
	char tmp[] = "asdasd";
	char* s = tmp;

	int e = 20;
	int* f = &e;
	defaultPrint(a);

	Content<std::list,int> content;
	std::list vec = { 1,2,3,4,5 };
	content.stlPrint(vec);
	std::cout << std::endl;

	std::cout << sumA(1, 2.11, 83, 22.33, 4.99) << std::endl;

	std::cout << stringStrcat("hello", "world") << std::endl;

	isPrint(f);
	return 0;
}