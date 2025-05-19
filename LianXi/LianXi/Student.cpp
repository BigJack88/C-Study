#include "Student.h"

Student::Student(const Student& other)
{
	_name = other._name;
	_age = other._age;
	_data = new int();
	*_data = *(other._data);
}
Student& Student::operator=(const Student& other)
{
	if (this == &other) return *this;
	_name = other._name;
	_age = other._age;
	*_data = *(other._data);
}
Student::Student(Student&& other) noexcept
{
	_name = std::move(other._name);
	_age = std::move(other._age);
	_data = new int();
	*_data = std::move(*(other._data));
}
Student& Student::operator=(Student&& other) noexcept
{
	if (this == &other) return *this;
	_name = std::move(other._name);
	_age = std::move(other._age);
	*_data = std::move(*(other._data));
	return *this;
}
int Student::_num = 20;
Student::~Student()
{
	delete _data;
}
