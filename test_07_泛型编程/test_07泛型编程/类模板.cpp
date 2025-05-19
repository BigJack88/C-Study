/*
#include <iostream>
using namespace std;

template <class A>
class Div
{
private:
	A sum = 0;
public:
	Div() {};
	void usingDiv(A a, A b);
	~Div() {};
};

template <class A>
void Div<A>::usingDiv(A a, A b)
{
	sum = a / b;
	cout << sum << endl;
}



class Player
{
public:
	void run()
	{
		cout << "我在跑步" << endl;
	}
};
class Cat
{
public:
	void say()
	{
		cout << "我在喵叫" << endl;
	}
};

template <class B>
class Test
{
	B Obj;
public:
	Test() {};
	// 当没有明确类型时 这两个函数是不存在的
	void move1()
	{
		Obj.run();
	}
	void move2()
	{
		Obj.say();
	}
};
// main函数始终为普通函数 不能是函数模板

int main()
{
	Div <double> fl;
	fl.usingDiv(6, 3);


	Test<Player> a;
	a.move1();
	Test<Cat> b;
	b.move2();
	return 0;
}
*/