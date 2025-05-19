#pragma once
#include <iostream>
class Student
{
public:
	Student(std::string name, size_t age) :_name(name), _age(age) { _data = new int(); };
	Student(const Student& other);
	Student& operator=(const Student& other);
	Student(Student&& other) noexcept;
	Student& operator=(Student&& other) noexcept;
	~Student();
private:
	std::string _name;
	size_t _age;
	int* _data;
	static int _num;
};

