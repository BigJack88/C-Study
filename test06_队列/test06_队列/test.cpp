#include <iostream>
#include <stdexcept>
using namespace std;
/*
template<typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T d) :data(d), next(NULL) {};
	};
	Node* front;//队头
	Node* rear; // 队尾
	int size; // 队列人数
public:
	Queue() :front(NULL), rear(NULL), size(0) {};
	~Queue();
	void enQueue(T element); // 入队
	T deQueue();		// 出队
	T getFront() const; // 获取队头
	int getSize() const;	// 获取队列人数
};
template<typename T>
Queue<T>::~Queue()
{
	while (front)
	{
		Node* tmp = front;
		front = front->next;
		delete tmp;
	}
};
template<typename T>
void Queue<T>::enQueue(T element) // 入队
{
	if (rear == NULL)
	{
		rear = new Node(element);
		front = rear;
	}
	else
	{
		rear->next = new Node(element);
		rear = rear->next;
	}
	++size;
};
template<typename T>
T Queue<T>::deQueue() // 出队
{
	if (front == NULL)
	{
		throw std::underflow_error("Front is NULL");
	}
	else
	{
		T element = front->data;
		Node* tmp = front;
		front = front->next;
		delete tmp;
		size--;
		if (size == 0) // size为空时 rear地址已经被删除了 
		{
			rear = NULL; // 需要至为空 否则是野指针
		}
		return element;
	}
	
};		
template<typename T>
T Queue<T>::getFront() const  // 获取队头
{
	if (front == NULL)
	{
		throw std::underflow_error("Front is NULL");
	}
	return front->data;
};
template<typename T>
int Queue<T>::getSize() const
{
	return size;
};	// 获取队列人数


int main()
{
	Queue<int> q;
	q.enQueue(3);
	q.enQueue(4);
	cout << q.getFront() << endl;
	q.deQueue();
	cout << q.getFront() << endl;
	cout << q.getSize() << endl;
	return 0;
}
*/


/*STL实现队列*/
#include <queue>
/*
int main()
{
	queue<int> q;
	q.push(3);
	q.push(5);
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
*/


/*
士兵训练队列
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		queue<int> q1;
		queue<int> q2;
		// 将元素全部压入主队列
		for (int i = 1; i <= n; ++i)
		{
			q1.push(i);
		}
		int cnt = 0; // 报数号
		while (q1.size() > 3)
		{
			cnt = 0;
			while (q1.size())
			{
				// 全部出队 且将不符合条件的再压入副队列
				int go = q1.front();
				q1.pop();
				++cnt;
				if (cnt % 2 == 1)
				{
					q2.push(go);
				}
			}
			while (q2.size() <= 3)
			{
				while (!q2.empty())// 因为最后用q1打印，所以要将剩下的元素全放在q1上
				{
					q1.push(q2.front());
					q2.pop();
				}
				break;
			}
			cnt = 0; //清空报数号
			while (q2.size())
			{
				int go = q2.front();
				q2.pop();
				++cnt;
				if (cnt % 3 == 1 || cnt % 3 == 2)
				{
					q1.push(go);
				}
			}
		}
		// 打印最后的编号
		bool flag = true;
		while (q1.size())
		{
			if (!flag)
			{
				cout << ' ';
			}
			cout << q1.front();
			q1.pop();
			flag = false;
		}
		cout << endl;
	}
	return 0;
}
*/
// 顺逆报数  在报到最后一个人时 从后往前再报 
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> mainQu;
	vector<int> stk;
	int i = 0;
	for (i = 1; i <= n; ++i)
	{
		mainQu.push_back(i);
	}
	int cnt = 0;
	while (mainQu.size() > k - 1)
	{
		cnt = 0;
		while (mainQu.size())
		{
			int go = mainQu.front();
			mainQu.erase(mainQu.begin());
			cnt++;
			if (cnt % k == 0)
			{
				cout << go << ' ';
			}
			else
			{
				stk.push_back(go);
			}
		}
		if (stk.size() <= k - 1)
		{
			break;
		}
		cnt = 0;
		while (stk.size())
		{
			int go = stk.back();
			stk.pop_back();
			cnt++;
			if (cnt % k == 0)
			{
				cout << go << ' ';
			}
			else
			{
				// vector模拟栈的话 可以让栈尾部元素插入队列头部
				mainQu.insert(mainQu.begin(), go);
			}
		}
	}
	return 0;
}