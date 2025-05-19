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

// ֱ��ָ������
void test(Hero <string, double>& h) {};

// ����ģ��
template <typename T1,typename T2>
void test(Hero <T1, T2>& h) {};

// ��ģ��
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