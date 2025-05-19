#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <utility>

template <typename Key, typename T>
struct ThreeNode
{
	std::pair<Key, T> _data;
	ThreeNode<Key, T>* _left;
	ThreeNode<Key, T>* _right;
	ThreeNode<Key, T>* _parent;
	ThreeNode(const Key& key, const T& value, ThreeNode<Key, T>* parent = nullptr) :
		_data(std::make_pair(key,value)), _left(nullptr), _right(nullptr), _parent(parent) {};
};
template <typename Key, typename T>
class BstMap
{
public:
	BstMap() :_root(nullptr) {};
	// ����
	void insert(const Key& key, const T& value) 
	{
		if (_root == nullptr)
		{
			_root = new ThreeNode<Key, T>(key, value);
			return;
		}
		ThreeNode<Key, T> * current = _root;
		ThreeNode<Key, T> * prve = nullptr;
		while (current != nullptr)
		{
			prve = current;
			if (key < current->_data.first)
			{
				current = current->_left;
			}
			else if (key > current->_data.first)
			{
				current = current->_right;
			}
			else
			{
				current->_data.second = value;
				return;
			}
		}
		if (key < prve->_data.first)
		{
			prve->_left = new ThreeNode<Key, T>(key, value, prve);
		}
		else
		{
			prve->_right = new ThreeNode<Key, T>(key, value, prve);
		}
	};

	// ɾ��
	void erase(const Key& key)
	{
		auto itNode = find(key);
		if (itNode == nullptr) return;
		if (itNode->_left != nullptr && itNode->_right != nullptr)
		{
			auto successor = minimum(itNode->_right);
			itNode->_data = successor->_data;
			itNode = successor;
		}
		
		//�жϽڵ������ ������������������
		auto child = (itNode->_left) ? itNode->_left :itNode->_right; 
		if (child != nullptr)
		{
			child->_parent = itNode->_parent; // itNode��_parent ����itNodeԭ����λ��
		}

		// ���ڵ�����  ���������ӵ����ڵ���
		if (itNode->_parent == nullptr)
		{
			_root = child;
		}
		else if (itNode == itNode->_parent->_left) // �ж���������������
		{
			itNode->_parent->_left = child;
		}
		else
		{
			itNode->_parent->_right = child;
		}
		delete itNode;
	};

	// ����
	ThreeNode<Key, T>* find(const Key& key)
	{
		ThreeNode<Key, T>* current = _root;
		while (current != nullptr)
		{
			if (key < current->_data.first)
			{
				current = current->_left;
			}
			else if (key > current->_data.first)
			{
				current = current->_right;
			}
			else
			{
				return current;
			}
		}
		return nullptr;
	}


	// ������
	class Iterator
	{
	public:
		Iterator(ThreeNode<Key, T>* node) :current(node) {};
		std::pair<Key, T>& operator*() const { return current->_data; };
		std::pair<Key, T>* operator->() const { return &current->_data; };
		bool operator==(const Iterator& other) { return current == other.current; };
		bool operator!=(const Iterator& other) { return !(*this == other); };
		Iterator& operator++()
		{
			if (current != nullptr)
			{
				current = successor(current);
			}
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator tmp = *this;
			++(*this);
			return tmp;
		}
	private:
		ThreeNode<Key, T>* current;
		// �õ���ǰ�ڵ����������
		ThreeNode<Key, T>* minimum(ThreeNode<Key, T>* node) const
		{
			while (node->_left != nullptr)
			{
				node = node->_left;
			}
			return node;
		};
		// ����������еõ���ǰ�ڵ�ĺ�̽ڵ�
		ThreeNode<Key, T>* successor(ThreeNode<Key, T>* node) const
		{
			if (node->_right != nullptr)
			{
				return minimum(node->_right);
			}
			// �ų��������
			// 1.�����ǰ�ڵ�û�и��ڵ� ��ô��ǰ�ڵ����root�ڵ� ���һ��������������������
			// 2.�����ǰ�ڵ��Ǹ��ڵ�������� ��ô��ǰ�ڵ�ĺ�̽ڵ�һ���Ǹ��׽ڵ�
			auto parentNode = node->_parent;
			while (parentNode != nullptr && node == parentNode->_right)
			{
				node = parentNode;
				parentNode = parentNode->_parent;
			}
			return parentNode; // ��̽ڵ�
		};
		// ��ȡ���ڵ�
		ThreeNode<Key, T>* maxNode(ThreeNode<Key, T>* node) const
		{
			while (node->_right != nullptr)
			{
				node = node->_right;
			}
			return node;
		};
	};

	Iterator begin() const
	{
		return Iterator(minimum(_root));
	}
	Iterator end() const
	{
		return Iterator(nullptr);
	}

	// ����Ҫ����T& ���� �������ܱ���ֵ map[key] = 20;
	T& operator[](const Key& key)
	{
		ThreeNode<Key, T>* node = find(key);
		if (node != nullptr) return node->_data.second;
		insert(key, T());
		ThreeNode<Key, T>* insertNode = find(key);
		return insertNode->_data.second;
	};

	// ����>=key����С������
	Iterator lower_bound(const Key& key)
	{
		ThreeNode<Key, T>* current = _root;
		ThreeNode<Key, T>* candidate = nullptr;

		while (current != nullptr)
		{
			if (current->_data.first >= key)
			{
				candidate = current;           // �����Ǵ𰸣����������Ҹ�С��
				current = current->_left;
			}
			else
			{
				current = current->_right;     // ��ǰֵ̫С��������
			}
		}
		return Iterator(candidate);
	}
	// ����>key����С������
	Iterator upper_bound(const Key& key)
	{
		ThreeNode<Key, T>* current = _root;
		ThreeNode<Key, T>* result = nullptr;

		while (current != nullptr)
		{
			if (current->_data.first > key)
			{
				result = current;
				current = current->_left;
			}
			else
			{
				current = current->_right; 
			}
		}
		return Iterator(result);
	};

	// �������� �ṩ�ⲿ�ӿ�
	void clear()
	{
		clear(_root);
		_root = nullptr; // ��������ָ��
		std::cout << "Clear ThreeNode" << std::endl;
	};
	~BstMap()
	{
		clear();
	}
private:
	ThreeNode<Key, T>* _root;
	BstMap(const BstMap&) = delete;
	BstMap& operator=(const BstMap&) = delete;
	/*
		const ���γ�Ա��������ʾ�ú��������޸���ĳ�Ա���������� mutable ������
		ֻ�� const ��Ա���������� const �����ϱ�����
		��������ȷ���������ڲ� ֻ��const������ܵ������³�Ա����
	*/

	// ������нڵ�
	void clear(ThreeNode<Key, T>* node) const
	{
		if (node == nullptr) return;
		clear(node->_left);
		clear(node->_right);
		delete node;
	}

	// �õ���ǰ�ڵ����������
	ThreeNode<Key, T>* minimum(ThreeNode<Key, T>* node) const
	{
		while (node->_left != nullptr)
		{
			node = node->_left;
		}
		return node;
	};
	// ����������еõ���ǰ�ڵ�ĺ�̽ڵ�
	ThreeNode<Key, T>* successor(ThreeNode<Key, T>* node) const
	{
		if (node->_right != nullptr)
		{
			return minimum(node->_right);
		}
		// �ų��������
		// 1.�����ǰ�ڵ�û�и��ڵ� ��ô��ǰ�ڵ����root�ڵ� ���һ��������������������
		// 2.�����ǰ�ڵ��Ǹ��ڵ�������� ��ô��ǰ�ڵ�ĺ�̽ڵ�һ���Ǹ��׽ڵ�
		auto parentNode = node->_parent;
		while (parentNode != nullptr && node == parentNode->_right)
		{
			node = parentNode;
			parentNode = parentNode->_parent;
		}
		return parentNode; // ��̽ڵ�
	};
	// ��ȡ���ڵ�
	ThreeNode<Key, T>* maxNode(ThreeNode<Key, T>* node) const
	{
		while (node->_right != nullptr)
		{
			node = node->_right;
		}
		return node;
	};

};