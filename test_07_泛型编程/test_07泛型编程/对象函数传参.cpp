#include <iostream>
using namespace std;

template <typename Hero_hp, typename Hero_name>
class Hero
{
private:
	Hero_hp hp;
	Hero_name name;
public:
	Hero(Hero_hp hp, Hero_name name)
	{
		this->name = name;
		this->hp = hp;
	}
};

// 直接指定类型
void test(Hero <string, double>& h) {};

// 参数模板
template <typename T1,typename T2>
void test(Hero <T1, T2>& h) {};

// 类模板
template <class T>
void test(T & h) {};


int main()
{
	Hero <string,double>h("Admin",100);

	test(h);

	test<string, double>(h);

	test<Hero<string,double>>(h);
	return 0;
}