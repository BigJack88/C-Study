#include <iostream>
#include <functional>
#include <vector>
using Func = std::function<void(int)>;
void tiggerEvent(Func func, const int& value)
{
	func(value);
}
void funcAdd(const int& value)
{
	std::cout << value + value << std::endl;
}
struct strAdd
{
	void operator()(const int& value)
	{
		std::cout << value - value << std::endl;
	};
} strAdd;



int sum(const int& a,const int& b)
{
	return a + b;
}
int minus(const int& a, const int& b)
{
	return a - b;
}
int multiply(const int& a, const int& b)
{
	return a * b;
}
int except(const int& a, const int& b)
{
	return a / b;
}


class getExcept
{
public:
	double newExcept(const double& a, const double& b)
	{
		return a / b;
	}
};

int main()
{
	// std::function封装函数 有三种传入方法
	tiggerEvent([](int value) {
		std::cout << value * value << std::endl;
	}, 20);
	tiggerEvent(funcAdd, 10);
	tiggerEvent(strAdd, 70);
	std::cout << "---------------------------------------" << std::endl;

	//vector 存储函数指针
	std::vector<std::function<int(int,int)>> vec;
	vec.emplace_back(sum); // 尾插 -> 相对push_back少一次拷贝
	vec.emplace_back(minus); 
	vec.emplace_back(multiply);
	vec.emplace_back(except);
	for (auto& iter : vec)
	{
		std::cout << iter(10,20) << std::endl;
	}
	std::cout << "---------------------------------------" << std::endl;

	//std::bind绑定函数 设置占位符
	auto setSum = std::bind(sum, 10, std::placeholders::_1);
	setSum(80);
	auto reverMinus = std::bind(minus, std::placeholders::_2, std::placeholders::_1);
	std::cout << reverMinus(10, 70) << std::endl;

	// std::bind绑定成员函数
	getExcept getexcept;
	auto getNumber = std::bind(&getExcept::newExcept, &getexcept, std::placeholders::_1, std::placeholders::_2);
	std::cout << getNumber(40, 10) << std::endl;

	auto getNumber2 = [&getexcept](int a, int b) {
		return getexcept.newExcept(a, b);
	};
	std::cout << getNumber2(60, 30) << std::endl;
	
	return 0;
}