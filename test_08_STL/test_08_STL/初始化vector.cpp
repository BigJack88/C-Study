
#include "include.h"
/*
void printVector(vector<int>& v)
{
	for (vector<int>::iterator item = v.begin(); item != v.end(); item++)
	{
		cout << *item << " ";
	}
	cout << endl;

}

int main()
{
	//1. 默认构造
	vector<int> v1;
	printVector(v1);

	// 2. 初始化列表
	vector <int> v2_1 = { 1,2,3,4,5, };
	printVector(v2_1);
	vector <int> v2_2({ 5,4,3,2,1 });
	printVector(v2_2);

	// 3. 迭代初始化
	vector<int> v3(v2_1.begin(), v2_1.end());
	printVector(v3);

	//4. 全0初始化 -- 输入你要初始化为0的个数
	vector<int> v4(10);
	printVector(v4);

	//5. vector<int>变量名(a,b) , 申请a个空间元素，元素值为b
	vector<int> v5(8, 6);
	printVector(v5);

	//6. 拷贝构造函数
	vector <int> v6(v4);
	printVector(v6);

	//7. assign初始化和复制 a 个 b
	vector<int> v7;
	v7.assign(9,8);
	printVector(v7);

	// vector类的方法都是指针 解引用可以获取他的值
	// end()是数组最后一个元素的后一个空间
	cout << "首元素 " << *v2_1.begin() << endl;
	cout << "末尾元素 " << *(v2_1.end() - 1) << endl;
	cout << "容量 " << v2_1.capacity() << endl;
	cout << "首元素 " << v2_1.front() << endl;
	cout << "末尾元素 " << v2_1.back() << endl;

	return 0;
}

*/