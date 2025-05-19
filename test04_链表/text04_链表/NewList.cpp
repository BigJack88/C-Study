#include <iostream>

template <typename T>
struct Data
{
	T element;
	Data* next;
	Data(T value) :element(value), next(nullptr) {};
};
template <typename T>
class NewList
{
public:
	NewList() :_head(nullptr), _size(0) {};
	~NewList();
	void listInsert(int index,T value);
	void listRemove(int index);
	void listUpdate(int index,T value);
	Data<T>* listFind(int index);
	size_t getSize();
	void ListPrint();
private:
	Data<T> * _head;
	size_t _size;
};
template <typename T>
NewList<T>::~NewList()
{
	Data<T>* curr = _head;
	while (curr != nullptr)
	{
		Data<T>* toDelete = curr;
		curr = curr->next;
		delete toDelete;
	}
	_head = nullptr;
	_size = 0;
}
template <typename T>
void NewList<T>::listInsert(int index,T value)
{
	if (index > _size || index < 0) throw std::out_of_range("Index of range");
	Data<T>* newData = new Data<T>(value);
	if (index == 0)
	{
		newData->next = _head;
		_head = newData;
	}
	else
	{
		Data<T>* curr = _head;
		for (int i = 0; i < index - 1; ++i)
		{
			curr = curr->next;
		}
		newData->next = curr->next;
		curr->next = newData;
	}
	++_size;
}
template <typename T>
void NewList<T>::listRemove(int index)
{
	if (index >= _size || index < 0) throw std::out_of_range("Index of range");
	if (index == 0)
	{
		Data<T>* toDelete = _head;
		_head = _head->next;
		delete toDelete;
	}
	else
	{
		Data<T>* curr = _head;
		for (int i = 0; i < index - 1; ++i)
		{
			curr = curr->next;
		}
		Data<T>* toDelete = curr->next;
		curr->next = toDelete->next;
		delete toDelete;
	}
	--_size;
}
template <typename T>
Data<T> *NewList<T>::listFind(int index)
{
	if (index >= _size || index < 0) throw std::out_of_range("Index of range");
	Data<T>* curr = _head;
	for (int i = 0; i < index; ++i)
	{
		curr = curr->next;
	}
	return curr;
}
template <typename T>
void NewList<T>::listUpdate(int index, T value)
{
	if (index >= _size || index < 0) throw std::out_of_range("Index of range");
	listFind(index)->element = value;
}
template <typename T>
size_t NewList<T>::getSize()
{
	return _size;
}
template <typename T>
void NewList<T>::ListPrint()
{
	Data<T>* curr = _head;
	while (curr != nullptr)
	{
		std::cout << curr->element << " ";
		curr = curr->next;
	}
}

int main()
{
	NewList<double> nl;
	nl.listInsert(0,2.11);
	nl.listInsert(1,3.22);
	nl.listInsert(2,4.33);
	nl.listInsert(3,5.44);
	nl.listInsert(4,6.55);

	nl.ListPrint();
	nl.listRemove(2);
	std::cout << std::endl;
	nl.ListPrint();
	nl.listUpdate(2, 10.22);
	std::cout << std::endl;
	nl.ListPrint();
	std::cout << std::endl;
	std::cout << nl.getSize() << std::endl;
	return 0;
}




