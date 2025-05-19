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
	// 插入
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

	// 删除
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
		
		//判断节点的子树 是左子树还是右子树
		auto child = (itNode->_left) ? itNode->_left :itNode->_right; 
		if (child != nullptr)
		{
			child->_parent = itNode->_parent; // itNode的_parent 就是itNode原本的位置
		}

		// 单节点的情况  将子树连接到父节点上
		if (itNode->_parent == nullptr)
		{
			_root = child;
		}
		else if (itNode == itNode->_parent->_left) // 判断是左树还是右树
		{
			itNode->_parent->_left = child;
		}
		else
		{
			itNode->_parent->_right = child;
		}
		delete itNode;
	};

	// 查找
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


	// 迭代器
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
		// 得到当前节点的最左子树
		ThreeNode<Key, T>* minimum(ThreeNode<Key, T>* node) const
		{
			while (node->_left != nullptr)
			{
				node = node->_left;
			}
			return node;
		};
		// 在中序遍历中得到当前节点的后继节点
		ThreeNode<Key, T>* successor(ThreeNode<Key, T>* node) const
		{
			if (node->_right != nullptr)
			{
				return minimum(node->_right);
			}
			// 排除两种情况
			// 1.如果当前节点没有父节点 那么当前节点就是root节点 后继一定是右子树的最左子树
			// 2.如果当前节点是父节点的左子树 那么当前节点的后继节点一定是父亲节点
			auto parentNode = node->_parent;
			while (parentNode != nullptr && node == parentNode->_right)
			{
				node = parentNode;
				parentNode = parentNode->_parent;
			}
			return parentNode; // 后继节点
		};
		// 获取最大节点
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

	// 这里要返回T& 类型 这样才能被赋值 map[key] = 20;
	T& operator[](const Key& key)
	{
		ThreeNode<Key, T>* node = find(key);
		if (node != nullptr) return node->_data.second;
		insert(key, T());
		ThreeNode<Key, T>* insertNode = find(key);
		return insertNode->_data.second;
	};

	// 返回>=key且最小的子树
	Iterator lower_bound(const Key& key)
	{
		ThreeNode<Key, T>* current = _root;
		ThreeNode<Key, T>* candidate = nullptr;

		while (current != nullptr)
		{
			if (current->_data.first >= key)
			{
				candidate = current;           // 可能是答案，尝试往左找更小的
				current = current->_left;
			}
			else
			{
				current = current->_right;     // 当前值太小，往右找
			}
		}
		return Iterator(candidate);
	}
	// 返回>key且最小的子树
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

	// 函数重载 提供外部接口
	void clear()
	{
		clear(_root);
		_root = nullptr; // 避免悬空指针
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
		const 修饰成员函数，表示该函数不会修改类的成员变量，除了 mutable 变量。
		只有 const 成员函数可以在 const 对象上被调用
		这种做法确保了在类内部 只有const对象才能调用以下成员函数
	*/

	// 清除所有节点
	void clear(ThreeNode<Key, T>* node) const
	{
		if (node == nullptr) return;
		clear(node->_left);
		clear(node->_right);
		delete node;
	}

	// 得到当前节点的最左子树
	ThreeNode<Key, T>* minimum(ThreeNode<Key, T>* node) const
	{
		while (node->_left != nullptr)
		{
			node = node->_left;
		}
		return node;
	};
	// 在中序遍历中得到当前节点的后继节点
	ThreeNode<Key, T>* successor(ThreeNode<Key, T>* node) const
	{
		if (node->_right != nullptr)
		{
			return minimum(node->_right);
		}
		// 排除两种情况
		// 1.如果当前节点没有父节点 那么当前节点就是root节点 后继一定是右子树的最左子树
		// 2.如果当前节点是父节点的左子树 那么当前节点的后继节点一定是父亲节点
		auto parentNode = node->_parent;
		while (parentNode != nullptr && node == parentNode->_right)
		{
			node = parentNode;
			parentNode = parentNode->_parent;
		}
		return parentNode; // 后继节点
	};
	// 获取最大节点
	ThreeNode<Key, T>* maxNode(ThreeNode<Key, T>* node) const
	{
		while (node->_right != nullptr)
		{
			node = node->_right;
		}
		return node;
	};

};