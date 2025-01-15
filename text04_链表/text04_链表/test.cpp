#include <iostream>
#include <stdexcept> // 处理异常
using namespace std;

#define eleType int
// 链表结点
struct ListNode
{
	eleType data;
	ListNode* next;
	ListNode(eleType x):data(x),next(NULL){}
};
class LinkedList
{
private:
	ListNode* head; // 链表头
	int size;	// 链表元素个数
public:
	LinkedList() :head(NULL), size(0) {};
	~LinkedList();	// 析构函数
	void insert(int i, eleType value);	// 插入
	void remove(int i);	// 删除
	ListNode* find(eleType value); // 寻找对应的值
	ListNode* get(int i);	// 寻找对应下标
	void update(int i, eleType value);	// 更新对应链表
	void print();	// 打印链表
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
	// 判断插入位置是否正确
	if (i < 0 || i > size)
	{
		throw std::out_of_range("Invaild Position");
	}
	ListNode* newNode = new ListNode(value); // 生成新的结点 并且调用初始函数为value
	if (i == 0)
	{
		newNode->next = head; // newNode->next 先指向要替换掉的链表头
		head = newNode; // 这里用newNode覆盖head 则 head->next指向上一个链表头
	}
	else
	{
		ListNode* curr = head; // 游离节点 来遍历链表
		for (int j = 0; j < i - 1; ++j) // 遍历到要插入结点的前一个结点
		{
			curr = curr->next;
		}
		// 这两行不可替换顺序
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
		ListNode* tmp = head; // 将要删除的头结点地址存储起来
		head = head->next;
		delete tmp; // 删除这个已经游离的结点
	}
	else
	{
		ListNode* curr = head; 
		for (int j = 0; j < i - 1; ++j) // 遍历到要删除结点的前一个结点
		{
			curr = curr->next;
		}
		ListNode* tmp = curr->next;  // 找到要删除的结点 并且存储到tmp中
		curr->next = tmp->next;		// 把要删除结点的指针域 赋值给要删除结点的前一个结点
		delete tmp;					// 最后把这个游离的结点删除掉
	}
	--size;
}

ListNode* LinkedList::find(eleType value)
{
	ListNode* curr = head;
	while (curr && curr->data != value) // 当结点为真 并且 结点的值不等于要找的值时 移动结点 
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
	// 调用get函数找到对应的结点
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
// 链表解决斐波那契
int main()
{
	LinkedList l;
	l.insert(0, 1); // 作为表头 不在实际输出中
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
// 返回倒数第 k 个节点
class Solution {
public:
	int kthToLast(ListNode* head, int k) {
		// 快慢指针
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
// 移除重复节点
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
// 递归反转链表
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		// 假设链表已经反转完成
		ListNode* newHead = reverseList(head->next);
		head->next->next = head; // 将反转完的链表 指向最开始的head
		head->next = NULL;
		return newHead;
	}
};
*/

// 循环反转链表
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
// 给定两个链表 请计算他们相加和的值 并把值放入新链表
// 243   564 ->  708
// l1 = [9,9,9,9,9,9,9], r2 = [9,9,9,9] -> [8,9,9,9,0,0,0,1]

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* r1) {
		ListNode* retList = new ListNode(0);
		ListNode* newList = retList;
		int carry = 0;
		while (l1 != NULL || r1 != NULL) // 当两个链表的节点都为空才停止循环
		{
			int a = l1 ? l1->val : 0;	// 当前节点为空 则赋值0
			int b = r1 ? r1->val : 0;
			int sum = a + b + carry;
			carry = sum / 10;	// 计算进位
			sum %= 10;	// 取模得到赋值
			newList->next = new ListNode(sum); // new新节点赋值
			newList = newList->next;
			if (l1 != NULL)	// 节点不为空则 移动下一个节点
			{
				l1 = l1->next;
			}
			if (r1 != NULL)
			{
				r1 = r1->next;
			}

		}
		if (carry == 1)	// 循环结束时 还有进位 则再建一个节点赋值
		{
			newList->next = new ListNode(carry);
		}
		return retList->next;
	}
};
*/

/*
// 合并两个有序链表
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
