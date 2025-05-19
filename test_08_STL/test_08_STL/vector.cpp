#include "include.h"


/*
void printVector(vector<int>& v,string str)
{
	cout << str << ":";
	for (vector<int>::iterator item = v.begin(); item != v.end(); item++)
	{
		cout << *item << ' ';
	}
	cout << endl;
}

int main()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// 插入
	v1.insert(v1.begin()+2, 888);
	printVector(v1, "v1");
	insert(v2.end(),v2.begin(),v2.end()) // 范围插入(插入位置，从哪开始，从哪结束)

	// 删v1除
	v1.pop_back();
	printVector(v1, "v1");
	vector<int>::iterator item = v1.erase(v1.begin()+1); // erase必须使用begin()或end()
	printVector(v1, "v1");
	cout << *item << endl; // 迭代器返回删除元素的后一个元素

	//清空 -- 清空size() 但是capacity()依然占有内存
	// v1.clear(); 
	// printVector(v1,"v1");

	// 访问数组中元素
	// cout << v1.at(12) << endl; // 越界会提示异常
	// cout << v1[12] << endl; // 越界不会提示异常 - 但效率高


	// 扩容 -- 改变size的大小 如果size大于capacity 则进行1.5倍扩容
	v1.resize(200);  
	cout << "v1:" << v1.size() << endl;
	cout << "v1:" << v1.capacity() << endl;
	printVector(v1, "v1");
	cout << endl;

	// 缩容
	v1.resize(5);
	// 拷贝构造函数后size的值与capacity相等
	// 使用匿名函数拷贝构造v1 此时匿名函数中capacity的值已经回调 再调用swap方法交换v1的地址
	vector<int>(v1).swap(v1); 
	cout << "v1:" << v1.size() << endl;
	cout << "v1:" << v1.capacity() << endl;
	printVector(v1, "v1");
	cout << endl;

	//***内存清理
	v1.resize(10000);
	vector<int>({}).swap(v1);
	cout << "v1:" << v1.size() << endl;
	cout << "v1:" << v1.capacity() << endl;
	printVector(v1, "v1");
	cout << endl;

	//空间预留
	vector<int> v2;
	v2.reserve(100); // 修改capacity的值
	for (int i = 0; i < 100; i++)
	{
		//在已知要开辟空间大小时 提前修改capacity的值可以提升效率
		v2.push_back(i);
	}
	cout << "v2:" << v2.size() << endl;
	cout << "v2:" << v2.capacity() << endl;
	printVector(v2, "v2");

	//获取vector中最大和最小值 返回地址
	int maxPosition = max_element(n.begin(),n.end()) - n.begin(); //最大值下标

	int minPosition = min_element(n.begin(),n.end()) - n.begin();//最小值下标

	2）普通数组
	int a[]={1,2,3,4};
	int maxPosition = max_element(a,a+2) - a; //最大值下标

	int minPosition = min_element(a,a+2) - a;//最小值下标

	// 数组去重
	// unique将重复元素移动到数组的末尾 并且返回一个移除数据起始范围的迭代器
	// 再调用erase删除
	v.erase(unique(v.begin(), v.end()), v.end());
	return 0;
}
*/