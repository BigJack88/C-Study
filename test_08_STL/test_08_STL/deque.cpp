#include "include.h"
/*
void printDeque(deque<int>& v, string str)
{
	cout << str << ":";
	for (deque<int>::iterator item = v.begin(); item != v.end(); item++)
	{
		cout << *item << ' ';
	}
	cout << endl;
}

int main()
{
	// deque的对象创建与vector一致
	deque<int> de = { 1,2,3,4,5 };
	deque<int> dp(de.begin(), de.end());
	printDeque(dp, "dp:");
	//迭代器赋值
	deque<int> da;
	da.assign(dp.begin() + 1, dp.end());
	printDeque(da, "da:");

	// 插入
	// 与vector不同的是多了个前插
	de.push_front(-1);
	printDeque(de, "de:");

	// 删除
	// 与vector不同的是多了个前删
	dp.pop_front();
	printDeque(dp, "dp:");
	return 0;
}
*/