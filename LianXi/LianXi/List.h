#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T _data;
	Node<T>* next;
	Node<T>* prev;
	Node(const T& data = T()) :_data(data), next(nullptr), prev(nullptr) {};
};
template <typename T>
class List;

template <typename T>
class Iterator
{
public :
	using self_type = Iterator<T>;
	using value_type = T;
	using pointer = T*;
	using reference = T&;
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = ptrdiff_t;

	Iterator(Node<T>* ptr = nullptr) : _nodePtr(ptr) {};
	reference operator*() { return _nodePtr->_data; };
	pointer operator->() { return &_nodePtr->_data; };
	self_type operator++()
	{
		if (_nodePtr != nullptr) _nodePtr = _nodePtr->next;
		return *this;
	}
	self_type operator++(int)
	{
			self_type beforThis = *this;
			++(*this);
			return beforThis;
	}
	self_type operator--()
	{
		if (_nodePtr != nullptr) _nodePtr = _nodePtr->prev;
		return *this;
	}
	self_type operator--(int)
	{

			self_type beforThis = *this;
			--(*this);
			return beforThis;
	}
	bool operator==(const self_type& other) const
	{
		return _nodePtr == other._nodePtr;
	}
	bool operator!=(const self_type& other) const
	{
		return _nodePtr != other._nodePtr;
	}
private:
	Node<T>* _nodePtr;
	friend class List<T>;
};

template <typename T>
class List
{
public:
	using iterator = Iterator<T>;
	List()
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->next = _tail;
		_tail->prev = _head;
	}
	iterator insert(iterator iter, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* current = iter._nodePtr;
		Node<T>* prevNode = current->prev;

		newNode->next = current;
		newNode->prev = prevNode;
		
		prevNode->next = newNode;
		current->prev = newNode;

		return iterator(newNode);
	}
	iterator begin()
	{
		return iterator(_head->next);
	}
	iterator end()
	{
		return iterator(_tail);
	}

	iterator erase(iterator iter)
	{
		if (iter == _head || iter == _tail)
		{
			return end();
		}
		Node<T>* current = iter._nodePtr;
		Node<T>* prevNode = current->prev;
		Node<T>* nextNode = current->next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		current->next = nullptr;
		current->prev = nullptr;
		delete current;
	}
	void push_back(const T& value)
	{
		insert(end(), value);
	}
	void push_front(const T& value)
	{
		insert(begin(), value);
	}
	void pop_back()
	{
		if (empty()) return;
		erase(_tail->prev);
	}
	void pop_front()
	{
		if (empty()) return;
		erase(begin());
	}
	bool empty()
	{
		return _head->next == _tail;
	}
	T& front()
	{
		return _head->next->_data;
	}
	T& back()
	{
		return _tail->prev->_data;
	}
	size_t getSize()
	{
		size_t count = 0;
		for (auto it = begin(); it != end(); it++)
		{
			count++;
		}
		return count;
	}
	void remove(const T& value)
	{
		for (auto it = begin(); it != end(); it++)
		{
			if (value == *it)
			{
				erase(it);
				break;
			}
		}
	}
	void listprit()
	{
		Node<T>* curr = _head->next;
		while (curr != _tail)
		{
			std::cout << curr->_data << " ";
			curr = curr->next;
		}
	}
	void clearList()
	{
		Node<T>* curr = _head->next;
		while (curr != _tail)
		{
			Node<T>* tmp = curr;
			curr = curr->next;
			delete tmp;
		}
		_head->next = _tail;
		_tail->prev = _head;
	}
	~List()
	{
		clearList();
		_head = nullptr;
		_tail = nullptr;
	}
private:
	Node<T>* _head;
	Node<T>* _tail;
	size_t _listSize;
};

