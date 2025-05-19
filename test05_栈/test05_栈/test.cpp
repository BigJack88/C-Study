#include <iostream>
#include <stdexcept>
#include <stack>
using namespace std;
/*
template <typename T>
class Stack
{
private:
	T* data;
	int size;
	int capcity;
	void resize();
public:
	Stack(): data(new T[10]) ,size(0), capcity(10) {};
	~Stack();
	void push(T element);
	T pop();
	T top() const;
	int getSize() const;
};

template <typename T>
void Stack<T>::resize()
{
	//	两倍扩容
	int newCapcity = capcity * 2;
	T* newData = new T[newCapcity];
	for (int i = 0; i < size; ++i)
	{
		newData[i] = data[i];
	}
	delete[]data;
	data = newData;
	capcity = newCapcity;
}
template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}
template <typename T>
void Stack<T>::push(T element)
{
	if (size == capcity)
	{
		resize();
	}
	data[size++] = element;
}
template <typename T>
T Stack<T>::pop()
{
	if (size == 0)
	{
		throw std::underflow_error("Stack is Empty");
	}
	return data[--size];
}
template <typename T>
T Stack<T>::top() const
{
	if (size == 0)
	{
		throw std::underflow_error("Stack is Empty");
	}
	return data[size - 1]; // 这样值不变
}
template <typename T>
int Stack<T>::getSize() const
{
	return size;
}

int main()
{
	Stack<int> sta;
	sta.push(4);
	sta.push(17);
	sta.push(25);
	cout << sta.top() << endl;
	sta.pop();
	cout << sta.top() << endl;
	return 0;
}
*/

/* STL 
int main()
{
	stack<int> sta;
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);
	while (!sta.empty())
	{
		cout << sta.top() << endl;
		sta.pop();
	}
	return 0;

}
*/


// 将10进制转换成任意进制
/*
int main()
{
	int n, x;
	while (cin >> n >> x)
	{
		stack<int> sta;
		if (!n)
		{
			cout << '0 ' ;
			continue;
		}
		if (n < 0)
		{
			cout << '-';
			n = -n;
		}
		while (n)
		{
			sta.push(n % x);
			n /= x;
		}

		while (!sta.empty())
		{
			int x = sta.top();
			if (x > 10)
			{
				printf("%c", 'A' + x - 10);
			}
			else
			{
				printf("%d", x);
			}
			sta.pop();
		}
		cout << endl;
	}
	return 0;
}
*/


/*
单调栈移除链表中的节点
class Solution {
public:
	ListNode* removeNodes(ListNode* head) {
		// 递归
		// if(head == NULL)
		// {
		//     return NULL;
		// }
		// head->next = removeNodes(head->next);
		// if(head->next == NULL)
		// {
		//     return head;
		// }
		// if(head->val < head->next->val)
		// {
		//     return head->next;
		// }
		// return head;

		// 栈
		vector<ListNode*> stk;
		ListNode* dummy = new ListNode(1000000);
		stk.push_back(dummy);
		ListNode* curr = head;
		while (curr)
		{
			while (stk.back()->val < curr->val)
			{
				stk.pop_back();
			}
			stk.push_back(curr);

			curr = curr->next;
		}
		for (int i = 0; i < stk.size(); ++i)
		{
			stk[i]->next = stk[i + 1];
		}
		stk.back()->next = nullptr;
		return dummy->next;
	}
};

*/