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
		cout << "�����ܲ�" << endl;
	}
};
class Cat
{
public:
	void say()
	{
		cout << "��������" << endl;
	}
};

template <class B>
class Test
{
	B Obj;
public:
	Test() {};
	// ��û����ȷ����ʱ �����������ǲ����ڵ�
	void move1()
	{
		Obj.run();
	}
	void move2()
	{
		Obj.say();
	}
};
// main����ʼ��Ϊ��ͨ���� �����Ǻ���ģ��

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