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
	Node* front;//��ͷ
	Node* rear; // ��β
	int size; // ��������
public:
	Queue() :front(NULL), rear(NULL), size(0) {};
	~Queue();
	void enQueue(T element); // ���
	T deQueue();		// ����
	T getFront() const; // ��ȡ��ͷ
	int getSize() const;	// ��ȡ��������
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
void Queue<T>::enQueue(T element) // ���
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
T Queue<T>::deQueue() // ����
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
		if (size == 0) // sizeΪ��ʱ rear��ַ�Ѿ���ɾ���� 
		{
			rear = NULL; // ��Ҫ��Ϊ�� ������Ұָ��
		}
		return element;
	}
	
};		
template<typename T>
T Queue<T>::getFront() const  // ��ȡ��ͷ
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
};	// ��ȡ��������


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


/*STLʵ�ֶ���*/
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
ʿ��ѵ������
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
		// ��Ԫ��ȫ��ѹ��������
		for (int i = 1; i <= n; ++i)
		{
			q1.push(i);
		}
		int cnt = 0; // ������
		while (q1.size() > 3)
		{
			cnt = 0;
			while (q1.size())
			{
				// ȫ������ �ҽ���������������ѹ�븱����
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
				while (!q2.empty())// ��Ϊ�����q1��ӡ������Ҫ��ʣ�µ�Ԫ��ȫ����q1��
				{
					q1.push(q2.front());
					q2.pop();
				}
				break;
			}
			cnt = 0; //��ձ�����
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
		// ��ӡ���ı��
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
// ˳�汨��  �ڱ������һ����ʱ �Ӻ���ǰ�ٱ� 
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
				// vectorģ��ջ�Ļ� ������ջβ��Ԫ�ز������ͷ��
				mainQu.insert(mainQu.begin(), go);
			}
		}
	}
	return 0;
}