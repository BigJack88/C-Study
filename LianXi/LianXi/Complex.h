#pragma once
#include <iostream>
class Complex
{
public:
	Complex(const double real = 0.0, const double imag = 0.0) :_real(real), _imag(imag) {};
	Complex operator+(const Complex& other) const
	{
		return Complex(_real + other._real, _imag + other._imag);
	}
	Complex operator-(const Complex& other) const
	{
		return Complex(_real - other._real, _imag - other._imag);
	}
	friend std::ostream& operator<<(std::ostream& os, const Complex& other)
	{
		os << "(" << other._real;
		if (other._imag >= 0)
		{
			os << "+" << other._imag << "i)";
		}
		else
		{
			os << "-" << -other._imag << "i)";
		}
		return os;
	}
private:
	double _real;
	double _imag;
};

