#include <iostream>
#include <string>
#include <iomanip> // 设置有效数字位数 如果输出内容的字符数少于设置的宽度，剩余部分将用空格填充
#include <cmath> // 数学库
// 调用标准库中 std 这个命名空间的内容
using namespace std;
/*
flaot  4字节
double  8字节  --- 精度更高 --- 比赛使用
*/

/*

#define eps 1e-7 // 通常用这个值来做对比
int main()
{
	float a = 3.141592653542222222222222222f;
	double b = 3.14159265354111111111111111111111;
	cout << setprecision(20) << a << endl; // 更早出现误差
	cout << setprecision(20) <<b << endl;

	double c = 1.5e-5; // 1.5 * 10的负五次方
	cout  << c << endl;  // 存在误差但是可以忽略不计

	double x = 1.0 / 128379184612 * 128379184612;
	// fabs()取绝对值 < 0.000001  后面的小数不再对比
	if (fabs(x - 1) < eps)
	{
		cout << "判断相等" << endl;
	}
	return 0;
}
*/



// 字符加减和输出
/*
int main()
{
	char str = 'y';
	char str2 = 'z';
	// 字符在内存中是以ascll码存储的
	// 用整形强制类型转换也可以得到ascll码
	cout << (int)str << endl;
	cout << str2 - str << endl;
	return 0;
}
*/


// 转义字符 
/*
int main()
{
	char a = '\n'; // 代替了endl
	cout << "我是\"帅哥\"" << a; // 转义字符就加斜杠
	cout << "我的年龄是\077" << endl; // \0xx 代表着八进制中77的数
	return 0;
}
*/


// 布尔 0假 1真
/*
int main()
{
	bool flag1 = true;
	bool flag2 = false;
	cout << flag1 << endl << flag2 << endl;
	cout << sizeof(flag1) << endl; // 布尔类型一个字节
	return 0;
}
*/
// 前置++ 和 后置++问题
/*
int main()
{
	int i = 6;
	int a = 0;
	a = i++;	// 先赋值给a,下一次使用i时递增
	int b = 0;
	b = ++i; // 先递增，再赋值
	cout << a << endl << b << endl;
	return 0;
}
*/

#include <string.h>
/*
int main()
{
	// 整形输入
	int a = 0;
	cin >> a;
	cout << a << endl;
	// 浮点数输入
	double dou = 0;
	cin >> dou;
	cout << dou << endl;
	// 字符输入
	char b = 0;
	cin >> b;
	cout << b << endl;
	// 引入string头文件
	string c = "";
	cin >> c;
	cout << c << endl;
	// 布尔类型输入 输入除 0 和 1的其他值都是非法输入
	bool flag = 0;
	cin >> flag;
	cout << flag << endl;
}
*/

// countinue跳出本次循环
/*
int main()
{
	int i = 0;
	for (i = 0; i < 10; ++i)
	{
		if (i == 3)
		{
			continue;
		}
		cout << i << endl;
	}
	return 0;
}
*/

// 不断输入 a 和 b
// 计算他们的值
/*
int main()
{
	int a, b;
	// 只要cin的输入不是非法输入 就会一直循环
	while (cin >> a >> b)
	{
		cout << a + b << endl;
	}
	return 0;
}
*/	

//常量指针常量
/*
int main()
{
	int a = 1;
	int b = 2;
	// 1.
	// 指针常量
	// 不能被赋值 
	int* const ps = &a;
	// ps = &b; 错误 
	*ps = 3;

	//2.常量指针
	// 不能被解引用 
	const int* pa = &b;
	// *p = 2; 错误 
	pa = &a;
	cout << "a : " << a << endl;

	//3. 常量指针常量
	// 不能被解引用 和 赋值 
	const int* const pt = &a;
	// pt = &b 错误
	// pt = 10  错误 
	return 0;
}
*/

// 指针++
/*
int main()
{
	int arr[5] = { 5,4,3,2,1 };
	int* ps = arr;
	cout << "第四个元素是" << *(ps + 3) << endl;

	// ps++; // ps++ == (ps = ps + 1)
	// cout << "第个二元素是" << *ps << endl;

	for (int i = 0; i < 5; ++i)
	{
		*ps++ = i;
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}
*/

// 指针数组
/*
int main()
{
	char a[] = "I";
	char b[] = "Love";
	char c[] = "You";
	char * pstr[3];
	pstr[0] = a;
	pstr[1] = b;
	pstr[2] = c;
	for (int i = 0; i < 3; ++i)
	{
		cout << pstr[i] << ' ';
	}
	cout << endl;


	int mat[3][4] =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int* pmat[3];
	pmat[0] = mat[0];
	pmat[1] = mat[1];
	pmat[2] = mat[2];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << pmat[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
*/


//数组指针
/*
int main()
{
	int arr[3][4] =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int(*ps)[4];
	ps = arr;
	cout << ps << endl;	// 取二维数组第一行的地址
	cout << &arr[0] << endl;
}
*/


// 打印16位指针地址
/*
string getHex(int x)
{
	char buff[10];
	//sprintf_s() 把格式化的数据写入某个字符串
	sprintf_s(buff, "%X", (x & 0xFFFF)); // (x & 0xFFFF) 的意思是 取16进制地址的低四位
	return (string)buff; // 强制转换成字符串返回
}


int main()
{
	int arr[3][4] =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (j)
			{
				cout << ',';
			}
			int* p = &arr[i][j];
			cout << getHex((int)p); // 截取16进制后4位
		}
		cout << endl;
	}

	
	int* q[3] = { arr[0],arr[1],arr[2] };
	int(*p)[4];
	p = &arr[0];
	// 数组指针
	cout << "数组指针" << endl;
	for (int i = 0; i < 3; ++i)
	{
		string s = getHex((int)(p + i));
		cout << "第" << i << "个[4]数组的地址是" << s << endl;
	}

	// 指针数组
	cout << "指针数组（没啥用）" << endl; 
	for (int i = 0; i < 3; ++i)
	{
		string s = getHex((int)(q + i));  // 这里取的是&arr[0] 的地址 二级指针
		cout << "第" << i << "个q元素的地址是" << s << endl;
	}

}
*/


// 指针函数
/*
int* getArray(int a, int d, int n)
{
	int* ret = new int[n]; // 动态数组
	for (int i = 0; i < n; ++i)
	{
		// 首项a加i个公差d
		ret[i] = a + i * d;
	}
	return ret;
}
int main()
{
	//返回数组的首地址 并且用指针接收
	int* ans = getArray(5, 4, 10);
	for (int i = 0; i < 10; ++i)
	{
		//*(ans+i)
		cout << ans[i] << ' ';
	}
	return 0;
}
*/

// 指针函数类型定义
// typedef 定义指针函数类型
/*
typedef void (*ps)(int a, int b, int c );
void fun(int a, int b, int c)
{
	cout << a << b << c  << endl;
}

// 指针函数数组类型定义
typedef void (*pa[5])(int a, int b, int c, double d, float e);

void fn1(int a, int b, int c, double d, float e)
{
	cout << "fn1" << endl;
}
void fn2(int a, int b, int c, double d, float e)
{
	cout << "fn2" << endl;
}
void fn3(int a, int b, int c, double d, float e)
{
	cout << "fn3" << endl;
}
int main()
{
	// 函数指针
	ps Aps = fun;
	Aps(1, 2, 3);
	ps Bps = fun;
	Bps(2, 3, 4);

	// 函数指针数组
	pa psArr = { fn1 ,fn2 ,fn3 };
	return 0;
}
*/

// 结构体数组
/*
struct Book
{
	string name;
	double price;
	int value;
};
int main()
{
	// c++中可以直接写结构体名 省略struct
	Book book[3] =
	{
		{"数学",10.22,10},
		{"语文",20.22,20},
		{"英语",30.22,30},
	};
	for (int i = 0; i < 3; ++i)
	{
		cout << book[i].name << ' ' << book[i].price << ' ' << book[i].value << endl;
	}
	return 0;
}
*/

/*
struct Point
{
	double x,y;
};

struct Circle
{
	Point pt;
	double radius;
};
struct Circles
{
	Circle c[100];
	int size;
};


int main() {
	Circles cs =
	{
		{
			{{9,8},5}, // 每一组Circle类型的数据
			{{10,11},4},
		},
		2
	};
	for(int i = 0;i < cs.size; ++i)
	{
		Circle tmp = cs.c[i];
		cout << tmp.pt.x << ' ' << tmp.pt.y << ' ' << tmp.radius << endl;
	}
	return 0;
}
*/

/*
union的使用 和 构造函数初始化结构体成员
*/
/*
struct Info
{
	char _name[20];
	int _role;
	union
	{
		double score;
		char course[20];
	}_sc;
	//构造函数
	Info(const char name[20], int role, double s, const char c[20])
	{
		strcpy_s(_name, name);
		_role = role;
		if (s > 0)
		{
			// 因为作用域不同所以要用_sc去获取
			_sc.score = s;
		}
		if (strlen(c) > 0)
		{
			strcpy_s(_sc.course, c);
		}
	}
};


int main()
{
	Info a[4] =
	{
		Info("周老师",0,-1,"C++"),
		Info("周老师",0,-1,"Python"),
		Info("王同学",1,90,""),
		Info("刘同学",1,80,""),

	};
	for (int i = 0; i < 4; ++i)
	{
		if (a[i]._role == 0)
		{
			cout << a[i]._name << "是一位老师，他教的是" << a[i]._sc.course <<endl;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (a[i]._role == 1)
		{
			cout << a[i]._name << "是一位学生，他的成绩是" << a[i]._sc.score << endl;
		}
	}

	return 0;
}

*/

/*
new 和 delete
*/
/*
int main()
{
	// int* ptr = new int(10); 动态创建一块整形的内存大小 并且赋值10
	// int* ptr = new int[20]; 动态创建20个整形元素内存大小的数组 没有初始化元素 元素为随机值
	int* ptr = new int[20]();  // 动态创建20个整形元素内存大小的数组 初始化元素为零
	cout << *ptr << endl;
	delete ptr; // 释放内存
	ptr = NULL;
	return 0;
}
*/


/*
数组内存申请
*/
/*
// 求相邻两个数的的差
int* getGapList(int* arr, int size)
{
	int* ptr = new int[size - 1];
	// 这里不能使用局部变量 因为a是栈上的变量 不能作为返回值
	// int a[size-1]; return a;
	for (int i = 0; i < size - 1; ++i)
	{
		ptr[i] = arr[i + 1] - arr[i];
	}
	return ptr;
}

int main()
{
	int arr[10] = { 1,3,2,5,6,4,9,1,2,6 };
	int* ret = getGapList(arr, 10);
	for (int i = 0; i < 9; ++i)
	{
		cout << ret[i] << ' ';
	}
	delete[] ret; // 不加[]只会删除 数组第一个元素 加则删除整个数组
	ret = NULL;
	return 0;
}
*/

/*
引用: 1.必须初始化
	  2.初始化以后无法修改
*/
/*
int main()
{
	//int& a; 错误
	int a = 10, c = 6;
	int& b = a; // 相当于让a的别名为b
	b = c; // b = 6 a = 6
	cout << b << a << c;
	return 0;
}
*/


/*
引用的本质就是指针常量
*/
/*
int main()
{
	int a = 10;
	// int& b = a;
	// b = 20;

	// 这两段代码是等价的
	// 引用的本质

	int* const b = &a;
	*b = 20;
	return 0;
}
*/

/*
引用在传参时的特性
*/
/*
int countAddSum(int* arr, int size, int target, int& count)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == target)
		{
			sum += arr[i];
			// 跟指针类似 改变count的同时 实参也会改变
			count++;
		}
	}
	return sum;
}

int main()
{
	int arr[] = { 1,2,4,2,5,2,6,2,7,2,8};
	int c = 0;
	int ret = countAddSum(arr, 11, 2, c);
	cout << ret << ' ' << c;
	return 0;
}
*/
int main()
{
	long long n;
	long long tmp = 1;
	scanf_s("%d", &n);
	while (n % 10 != 0)
	{
		long long ret = n % 10;
		n = n / 10;
		printf("%lld", ret);
	}

	return 0;
}


