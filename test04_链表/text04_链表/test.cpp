#include <iostream>
#include <stdexcept> // �����쳣
using namespace std;

#define eleType int
// ������
struct ListNode
{
	eleType data;
	ListNode* next;
	ListNode(eleType x):data(x),next(NULL){}
};
class LinkedList
{
private:
	ListNode* head; // ����ͷ
	int size;	// ����Ԫ�ظ���
public:
	LinkedList() :head(NULL), size(0) {};
	~LinkedList();	// ��������
	void insert(int i, eleType value);	// ����
	void remove(int i);	// ɾ��
	ListNode* find(eleType value); // Ѱ�Ҷ�Ӧ��ֵ
	ListNode* get(int i);	// Ѱ�Ҷ�Ӧ�±�
	void update(int i, eleType value);	// ���¶�Ӧ����
	void print();	// ��ӡ����
	eleType sum();
};
LinkedList::~LinkedList()
{
	ListNode* curr = head;
	while (curr != NULL)
	{
		ListNode* tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}
void LinkedList::insert(int i, eleType value)
{
	// �жϲ���λ���Ƿ���ȷ
	if (i < 0 || i > size)
	{
		throw std::out_of_range("Invaild Position");
	}
	ListNode* newNode = new ListNode(value); // �����µĽ�� ���ҵ��ó�ʼ����Ϊvalue
	if (i == 0)
	{
		newNode->next = head; // newNode->next ��ָ��Ҫ�滻��������ͷ
		head = newNode; // ������newNode����head �� head->nextָ����һ������ͷ
	}
	else
	{
		ListNode* curr = head; // ����ڵ� ����������
		for (int j = 0; j < i - 1; ++j) // ������Ҫ�������ǰһ�����
		{
			curr = curr->next;
		}
		// �����в����滻˳��
		newNode->next = curr->next;
		curr->next = newNode;
	}
	++size;
}

void LinkedList::remove(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invaild Position");
	}
	if (i == 0)
	{
		ListNode* tmp = head; // ��Ҫɾ����ͷ����ַ�洢����
		head = head->next;
		delete tmp; // ɾ������Ѿ�����Ľ��
	}
	else
	{
		ListNode* curr = head; 
		for (int j = 0; j < i - 1; ++j) // ������Ҫɾ������ǰһ�����
		{
			curr = curr->next;
		}
		ListNode* tmp = curr->next;  // �ҵ�Ҫɾ���Ľ�� ���Ҵ洢��tmp��
		curr->next = tmp->next;		// ��Ҫɾ������ָ���� ��ֵ��Ҫɾ������ǰһ�����
		delete tmp;					// �����������Ľ��ɾ����
	}
	--size;
}

ListNode* LinkedList::find(eleType value)
{
	ListNode* curr = head;
	while (curr && curr->data != value) // �����Ϊ�� ���� ����ֵ������Ҫ�ҵ�ֵʱ �ƶ���� 
	{
		curr = curr->next;
	}
	return curr;
}

ListNode* LinkedList::get(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invaild Position");
	}
	ListNode* curr = head;
	for (int j = 0; j < i; ++j)
	{
		curr = curr->next;
	}
	return curr;
}
void LinkedList::update(int i, eleType value)
{
	// ����get�����ҵ���Ӧ�Ľ��
	get(i)->data = value;
}
void LinkedList::print()
{
	ListNode* curr = head;
	while (curr)
	{
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout << endl;
}
eleType LinkedList::sum()
{
	eleType ret = 0;
	ListNode* curr = head;
	while (curr)
	{
		ret += curr->data;
		curr = curr->next;
	}
	return ret;
}
/*
int main()
{
	LinkedList list;
	list.insert(0, 10);
	list.insert(1, 20);
	list.insert(2, 30);
	list.insert(3, 40);
	list.insert(4, 50);
	list.insert(5, 60);
	list.print();
	list.remove(2);
	list.print(); 
	list.update(2, 80);
	list.print();
	ListNode* tmp = list.find(80);
	cout << tmp->data << endl;
	return 0;
}
*/

/*
// ������쳲�����
int main()
{
	LinkedList l;
	l.insert(0, 1); // ��Ϊ��ͷ ����ʵ�������
	l.insert(1, 1);
	l.insert(2, 1);
	for (int i = 3; i <= 40; ++i)
	{
		ListNode* a = l.get(i - 1);
		ListNode* b = l.get(i - 2);
		l.insert(i, a->data + b ->data);
	}
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		cout << l.get(x)->data << endl;
	}
	return 0;
}
*/

/*
// ���ص����� k ���ڵ�
class Solution {
public:
	int kthToLast(ListNode* head, int k) {
		// ����ָ��
		ListNode* fast = head;
		while (k--)
		{
			fast = fast->next;
		}
		ListNode* slow = head;
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow->val;
	}
};
*/

/*
// �Ƴ��ظ��ڵ�
class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		bool hash[20001] = { 0 };
		ListNode* tmp = head;
		ListNode* curr = head->next;
		hash[head->val] = 1;
		while (curr)
		{
			if (!hash[curr->val])
			{
				hash[curr->val] = 1;
				tmp->next = curr;
				tmp = tmp->next;
			}
			curr = curr->next;
		}
		tmp->next = NULL;
		return head;
	}
};
*/

/*
// �ݹ鷴ת����
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		// ���������Ѿ���ת���
		ListNode* newHead = reverseList(head->next);
		head->next->next = head; // ����ת������� ָ���ʼ��head
		head->next = NULL;
		return newHead;
	}
};
*/

// ѭ����ת����
/*
class Solution {
public:
	ListNode* trainningPlan(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		ListNode* prev = NULL;
		ListNode* curr = head;
		while (curr)
		{
			ListNode* nextNode = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextNode;
		}
		return prev;
	}
};
*/

/*
// ������������ �����������Ӻ͵�ֵ ����ֵ����������
// 243   564 ->  708
// l1 = [9,9,9,9,9,9,9], r2 = [9,9,9,9] -> [8,9,9,9,0,0,0,1]

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* r1) {
		ListNode* retList = new ListNode(0);
		ListNode* newList = retList;
		int carry = 0;
		while (l1 != NULL || r1 != NULL) // ����������Ľڵ㶼Ϊ�ղ�ֹͣѭ��
		{
			int a = l1 ? l1->val : 0;	// ��ǰ�ڵ�Ϊ�� ��ֵ0
			int b = r1 ? r1->val : 0;
			int sum = a + b + carry;
			carry = sum / 10;	// �����λ
			sum %= 10;	// ȡģ�õ���ֵ
			newList->next = new ListNode(sum); // new�½ڵ㸳ֵ
			newList = newList->next;
			if (l1 != NULL)	// �ڵ㲻Ϊ���� �ƶ���һ���ڵ�
			{
				l1 = l1->next;
			}
			if (r1 != NULL)
			{
				r1 = r1->next;
			}

		}
		if (carry == 1)	// ѭ������ʱ ���н�λ ���ٽ�һ���ڵ㸳ֵ
		{
			newList->next = new ListNode(carry);
		}
		return retList->next;
	}
};
*/

/*
// �ϲ�������������
// 1 2 3
// 1 4 5 
// 1 1 2 3 4 5
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* retList = new ListNode(0);
		ListNode* prev = retList;
		while (list1 != NULL && list2 != NULL)
		{
			if (list1->val >= list2->val)
			{
				prev->next = list2;
				list2 = list2->next;
			}
			else
			{
				prev->next = list1;
				list1 = list1->next;
			}
			prev = prev->next;
		}
		ListNode* append = list1 == NULL ? list2 : list1;
		prev->next = append;
		return retList->next;
	}
};
*/
