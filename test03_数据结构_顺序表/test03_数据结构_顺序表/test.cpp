#include <iostream>
using namespace std;

#define eleType double

struct SequentialList
{
	eleType* elements;
	int size; // 数组元素个数
	int capacity; // 容量
};

// 初始化 
void initializeList(SequentialList* list, int capacity)
{
	list->elements = new eleType[capacity];
	list->size = 0;
	list->capacity = capacity;
}
// 销毁
void destroyList(SequentialList* list)
{
	delete[]list->elements;
}
// 获取size
int getSize(SequentialList* list)
{
	return list->size;
}
// 判断数组是否为空
bool isEmpty(SequentialList* list)
{
	return list->size == 0;
}
// 插入
void Insert(SequentialList* list, int index, eleType element)
{
	// 判断下标是否合法
	if (index < 0 || index > list->size)
	{
		throw std::invalid_argument("Invalid index");
	}
	if (list->size == list->capacity)
	{
		int newCapacity = list->capacity * 2;
		eleType* newElements = new eleType[newCapacity];
		for (int i = 0; i < list->size; ++i)
		{
			newElements[i] = list->elements[i];
		}
		delete[]list->elements;
		list->elements = newElements;
		list->capacity = newCapacity;
	}
	for (int i = list->size; i > index; --i)
	{
		list->elements[i] = list->elements[i - 1];
	}
	list->elements[index] = element;
	list->size++;
}

// 删除
void DeleteElement(SequentialList* list, int index)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}
	for (int i = index; i < list->size - 1; ++i)
	{
		list->elements[i] = list->elements[i + 1];
	}
	// 如果是删除最后一个元素的话则不会循环直接size--
	// 则访问不到这个元素了 
	list->size--;
}

// 查找索引值
int FindIndex(SequentialList* list, eleType element)
{
	for (int i = 0; i < list->size; ++i)
	{
		if (list->elements[i] == element)
		{
			return i;
		}
	}
	return -1;
}
// 查找值相同的元素 
eleType FindElement(SequentialList* list, int index)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}
	return list->elements[index];
}
// 修改对应的下标的元素
void UpdateElement(SequentialList* list, int index, eleType element)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}
	list->elements[index] = element;
}

/*
int main()
{
	SequentialList myList;
	initializeList(&myList, 10);
	for (int i = 0; i < 10; ++i)
	{
		Insert(&myList, i, i * 10);
	}

	cout << "Size :" << getSize(&myList) << endl;
	cout << "isEmpty :" << isEmpty(&myList) << endl;

	for (int i = 0; i < getSize(&myList); ++i)
	{
		cout << FindElement(&myList, i) << ' ';
	}
	cout << endl;

	UpdateElement(&myList, 3, 520);
	DeleteElement(&myList, 5);

	for (int i = 0; i < getSize(&myList); ++i)
	{
		cout << FindElement(&myList, i) << ' ';
	}
	cout << endl;
	cout << "FindIndex :" << FindIndex(&myList, 80) << endl;
	return 0;
}
*/

/*
vector顺序表
*/
/*
#include <vector>
int main()
{
	vector <int> list;
	for (int i = 0; i < 10; ++i)
	{
		list.push_back(i);
	}
	cout << list.size() << endl;
	for (int i = 0; i < list.size(); ++i)
	{
		cout << list[i] << ' ';
	}
	return 0;
}
*/

/*
//统计正数负数和零
double a[10000];
int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
		{
			double x;
			cin >> x;
			a[i] = x;
		}
		int pcut = 0;
		int ncut = 0;
		int zcut = 0;
		for (int i = 0; i < n; ++i)
		
			// 浮点数有误差 小于1e-8就不做为正数
			if (a[i] > 1e-8)
			{
				pcut++;
			}
			else if (a[i] < -1e-8)
			{
				ncut++;
			}
			else
			{
				zcut++;
			}
		}
		cout << ncut << zcut << pcut << endl;
	}
	return 0;
}
*/


/*
 去大小值 求平均分
*/
/*
int main()
{
	int n;
	while (cin >> n && n)
	{
		SequentialList list;
		initializeList(&list, 100);
		for (int i = 0; i < n; ++i)
		{
			eleType element;
			cin >> element;
			Insert(&list, i, element);
		}
		eleType max = -10000000000000;
		eleType min = 10000000000000;
		eleType sum = 0;
		for (int i = 0; i < getSize(&list); ++i)
		{
			eleType element = FindElement(&list, i);
			if (element > max)
			{
				max = element;
			}
			if (element < min)
			{
				min = element;
			}
			sum += element;
		}
		sum -= max;
		sum -= min;
		sum /= (n - 2);
		printf("%.2lf", sum);
	}
	return 0;
}
*/

/*
数组中两个元素的最大乘积
*/
/*
	int maxProduct(int nums[],int size) {
		int maxIndex = 0;
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] > nums[maxIndex])
			{
				maxIndex = i;
			}
		}
		int subIndex = -1;
		for (int i = 0; i < size; ++i)
		{
			if (i != maxIndex)
			{	
				 // 假设maxIndex的值是0 则 subIndex的初始值会与maxIndex的值相同
				if (nums[i] > nums[subIndex] || subIndex == maxIndex)
				{
					subIndex = i;
				}
			}
		}
		return (nums[maxIndex] - 1) * (nums[subIndex] - 1);
	}
int main()
{
	int list[5];
	for (int i = 0; i < 5; ++i)
	{
		cin >> list[i];
	}
	cout << maxProduct(list, 5);
	return 0;
}
*/

// for循环和双重for循环对顺序表的作用
/*
#define size 10
int main()
{
	int* arr = new int[10];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i;
	}
	
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	// 枚举i值右边的元素
	// 01234 1234 234 34 4
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			cout << arr[j];
		}
		cout << ' ';
	}
	cout << endl;
	// 枚举i值左边的元素
	// 这种是 01 012 0123 01234
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << arr[j];
		}
		cout << ' ';
	}
	cout << endl;
	// 例题 找到数组中间数  使得左边元素相加和右边元素相加相等
	for (int i = 0; i < size; ++i)
	{
		int l = 0, r = 0;
		// 枚举当前i值的左边元素
		for (int j = 0; j < i; ++j)
		{
			l += arr[j];
		}
		// 枚举当前i值的右边元素
		for (int j = i + 1; j < size; ++j)
		{
			r += arr[j];
		}
		// 两个值相等则返回
		if (l == r)
		{
			
		}
	}
	
	// 数组每次递增 2 
	// 判断 i 与 i + 1的关系时 size 要 - 1防止数组越界
	// 但是当数组元素数量是奇数时 最后一个数是检测不到的
	int ret = 0;
	int i = 0;
	for (i = 0; i < size - 1; i += 2)
	{
		if (arr[i] != arr[i + 1])
		{
			 
		}
	}
	//  if(arr[i])... 对数组的最后一个数额外进行判断;
	
	// 从左到右遍历数组 数组元素从右到左递减
	for (int i = size - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << arr[j];
		}
		cout << ' ';
	}
	cout << endl;
	return 0;
}
*/


// 位运算
/*
	& 位于 有0必0
*/
/*
int main()
{
	int a = 0b1010; // 10
	int b = 0b0110; // 6
	//a&b = 0b0010 // 2
	cout << "-----" << endl;

	//2.奇偶性
	cout << 5 % 2 << endl;	 // 优先级高，效率低
	cout << (5 & 1) << endl; // 优先级低，效率高
	// 0b0101  5 奇数二进制位最后一位永远是1
	// 0b0001  1
	cout << "-----" << endl;

	//3.获取一个数的二进制后5位
	int c = 0b010101011001;
	cout << (c & 0b11111) << endl; // 25
	cout << "-----" << endl;

	//4. 清除一个数的二进制后5位
	int d = 0b01010101;
	cout << (d & 0b111111111111111111111111111100000) << endl;
	cout << "-----" << endl;

	// 5. 消除连续末尾的1
	int e = 0b101111;
	// e+1= 0b110000;
	//      0b100000;
	cout << (e & e + 1) << endl;
	cout << "-----" << endl;

	// 6.判断是否是2的幂
	int f = 0b100000;
	// f-1= 0b011111 = 0
	f > 0 && (f & (f - 1)) == 0;


	return 0;
}
*/


/*
	| 位或 有1出1
*/
/*
int main()
{
	int a = 0b10110;
	int b = 0b11100;
	//      0b11110
	cout << (a | b) << endl;

	//1. 设置标志位
	int c = 0b10101;
	//      0b11101
	cout << (c | 0b01000) << endl;

	//2. 清空标志位
	int d = 0b10111;
	int m = 0b00001;// 魔法位 当d的魔法位没有1时 或上1 再相减
	//      0b10110
	cout << ((d | m) - m ) << endl;

	// 3. 低位连续的0 变 1
	int e = 0b101100;
	cout << (e | e-1) << endl;

	return 0;
}
*/

/*
	^ 全1出0
*/
/*
int main()
{
	// 任何数 ^0 还是他本身
	// 两个相同的数 ^ 等于 0
	// 异或：就是不带进位的二进制加法
	int a = 0b00010;
	int b = 0b00101;
	cout << (a ^ b) << endl;

	//1. 标记位取反
	int c = 0b10110;
	cout << (c ^ 0b100) << endl;
	cout << ((c ^ 0b100) ^ 0b100) << endl;

	//2. 变量交换
	int d = 17;
	int e = 19;
	d = d ^ e;
	e = d ^ e; // d' ^ e = d^e^e = d ^ 0 = d
	d = d ^ e; // d' ^ d = d^d^e = 0 ^ e = e
	cout << d << ' ' << e << endl;

	//3.出现奇数次的数

	//4. 加密
	int x = 1314;
	cout << (x ^ 2933) << endl;

	return 0;
}

*/

/*
	按位取反 ~
*/
/*
int main()
{
	int a = 0b000000000000000000000001;
	// 0b111111111111111111111110
	cout << (~a) << endl;

	//2. 求相反数 ~后+1
	int d = 10;
	cout << (~d + 1) << endl;
	//
	return 0;
}
*/

/*
	x << y = x * 2的y次方
*/

/*
int main()
{
	// 左移一位等于乘上2
	int x = 0b11; // 3;
	x = (x << 1); // 0b110
	cout << x << endl; // 6

	// 左移位数 不能是负数
	// 左移注意不要溢出
	int a = 64;
	cout << (a<<31) << endl; // 32位截断 == 0
	return 0;
}
*/

/*
	x >> y = x / 2的y次方
*/
/*
int main()
{
	int a = 0b110; //6
	a = (a >> 1);
	cout << a << endl;

	// 2. 负数右移  只有-1右移后等于-1 其他都除2 
	int b = -2;
	cout << (b >> 1) << endl;

	return 0;
}
*/


/*
经典例题
给你一个数组 nums ，数组中的数字 要么 出现一次，要么 出现两次。
请你返回数组中所有出现两次数字的按位 XOR 值，如果没有数字出现过两次，返回 
class Solution {
public:
	int duplicateNumbersXOR(vector<int>& nums) {
		int ans = 0;
		long long visited = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int x = nums[i];
			if (visited & ((long long)1 << x)) // 判断visited标志位是否有1
			{
				ans ^= x;
			}
			else
			{
				// 如果没有1则用 | 来把标志位设置成1
				// 1<<x 表示将1左移到64位二进制数的第x位 标记为1 
				// 再用& 来判断标志位上是否有1
				visited |= ((long long)1 << x);
			}
		}
		return ans;
	}
};
// 0000000000 0000000000 0000000000 0000101000 0000000000
*/
