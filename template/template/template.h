#pragma once
#include <iostream>
#include <type_traits>
template <typename T>
void defaultPrint(const T& value)
{
	std::cout << value << std::endl;
}

template <template <typename ,typename> class Continer,typename T>
class Content
{
public:
	void stlPrint(const Continer<T, std::allocator<T>>& continer)
	{
		for (auto& iter : continer)
		{
			std::cout << iter << " ";
		}
	}
};
template<typename...Args>
auto sumA(Args...args) -> decltype((args + ...))
{
	return (args + ...);
}
template <typename...Args>
std::string stringStrcat(const Args &...args)
{
	return (std::string{} + ... + args);
}


//SFINAE
template<typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type
isPrint(const T& value)
{
	std::cout << "Type is Int " << value << std::endl;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
isPrint(const T& value)
{
	std::cout << "Type is float " << value << std::endl;
}

template<typename T>
typename std::enable_if < std::is_same<T, const char*>::value || std::is_same<T,char*>::value , void > ::type
isPrint(const T& value)
{
	std::cout << "Type is C-string " << value << std::endl;
}

template<typename T>
typename std::enable_if < std::is_pointer<T>::value &&
	!std::is_same<T, const char*>::value &&
	!std::is_same<T, char*>::value, void > ::type
	isPrint(const T& value)
{
	std::cout << "Type is Pointer " << *value << std::endl;
}
