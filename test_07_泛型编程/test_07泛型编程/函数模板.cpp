#include <iostream>
using namespace std;

/*
template <typename T>
T sum(T& a, T& b)
{
	T c = a + b;
	return c;
}
template <typename T1,typename T2>
T2 add(T1& a, T2& b)
{
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
	T2 c = a + b;
	return c;
}
//在函数名相同时 如果函数形参数据类型 完美匹配 实参数据类型 则优先调用普通函数 反之调用模板函数



int main()
{
	double a = 1.22, b = 2.22;
	int a_2 = 2, b_2 = 'a';
	int c_2 = 0;
	// 函数自动推导类型 -- 形参的数据类型要一致
	double c = sum(a, b);
	cout << c << endl;

	// 显式指定类型 -- 限定传入函数的数据类型
	c_2 = sum<int>(a_2, b_2);
	cout << c_2 << endl;

	//有两个参数的函数模板 传入不同类型也可以调用模板
	cout << add(a_2, a) << endl;

	
	return 0;
}
*/


