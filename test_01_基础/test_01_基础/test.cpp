#include <iostream>
#include <string>
#include <iomanip> // ������Ч����λ�� ���������ݵ��ַ����������õĿ�ȣ�ʣ�ಿ�ֽ��ÿո����
#include <cmath> // ��ѧ��
// ���ñ�׼���� std ��������ռ������
using namespace std;
/*
flaot  4�ֽ�
double  8�ֽ�  --- ���ȸ��� --- ����ʹ��
*/

/*

#define eps 1e-7 // ͨ�������ֵ�����Ա�
int main()
{
	float a = 3.141592653542222222222222222f;
	double b = 3.14159265354111111111111111111111;
	cout << setprecision(20) << a << endl; // ����������
	cout << setprecision(20) <<b << endl;

	double c = 1.5e-5; // 1.5 * 10�ĸ���η�
	cout  << c << endl;  // �������ǿ��Ժ��Բ���

	double x = 1.0 / 128379184612 * 128379184612;
	// fabs()ȡ����ֵ < 0.000001  �����С�����ٶԱ�
	if (fabs(x - 1) < eps)
	{
		cout << "�ж����" << endl;
	}
	return 0;
}
*/



// �ַ��Ӽ������
/*
int main()
{
	char str = 'y';
	char str2 = 'z';
	// �ַ����ڴ�������ascll��洢��
	// ������ǿ������ת��Ҳ���Եõ�ascll��
	cout << (int)str << endl;
	cout << str2 - str << endl;
	return 0;
}
*/


// ת���ַ� 
/*
int main()
{
	char a = '\n'; // ������endl
	cout << "����\"˧��\"" << a; // ת���ַ��ͼ�б��
	cout << "�ҵ�������\077" << endl; // \0xx �����Ű˽�����77����
	return 0;
}
*/


// ���� 0�� 1��
/*
int main()
{
	bool flag1 = true;
	bool flag2 = false;
	cout << flag1 << endl << flag2 << endl;
	cout << sizeof(flag1) << endl; // ��������һ���ֽ�
	return 0;
}
*/
// ǰ��++ �� ����++����
/*
int main()
{
	int i = 6;
	int a = 0;
	a = i++;	// �ȸ�ֵ��a,��һ��ʹ��iʱ����
	int b = 0;
	b = ++i; // �ȵ������ٸ�ֵ
	cout << a << endl << b << endl;
	return 0;
}
*/

#include <string.h>
/*
int main()
{
	// ��������
	int a = 0;
	cin >> a;
	cout << a << endl;
	// ����������
	double dou = 0;
	cin >> dou;
	cout << dou << endl;
	// �ַ�����
	char b = 0;
	cin >> b;
	cout << b << endl;
	// ����stringͷ�ļ�
	string c = "";
	cin >> c;
	cout << c << endl;
	// ������������ ����� 0 �� 1������ֵ���ǷǷ�����
	bool flag = 0;
	cin >> flag;
	cout << flag << endl;
}
*/

// countinue��������ѭ��
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

// �������� a �� b
// �������ǵ�ֵ
/*
int main()
{
	int a, b;
	// ֻҪcin�����벻�ǷǷ����� �ͻ�һֱѭ��
	while (cin >> a >> b)
	{
		cout << a + b << endl;
	}
	return 0;
}
*/	

//����ָ�볣��
/*
int main()
{
	int a = 1;
	int b = 2;
	// 1.
	// ָ�볣��
	// ���ܱ���ֵ 
	int* const ps = &a;
	// ps = &b; ���� 
	*ps = 3;

	//2.����ָ��
	// ���ܱ������� 
	const int* pa = &b;
	// *p = 2; ���� 
	pa = &a;
	cout << "a : " << a << endl;

	//3. ����ָ�볣��
	// ���ܱ������� �� ��ֵ 
	const int* const pt = &a;
	// pt = &b ����
	// pt = 10  ���� 
	return 0;
}
*/

// ָ��++
/*
int main()
{
	int arr[5] = { 5,4,3,2,1 };
	int* ps = arr;
	cout << "���ĸ�Ԫ����" << *(ps + 3) << endl;

	// ps++; // ps++ == (ps = ps + 1)
	// cout << "�ڸ���Ԫ����" << *ps << endl;

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

// ָ������
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


//����ָ��
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
	cout << ps << endl;	// ȡ��ά�����һ�еĵ�ַ
	cout << &arr[0] << endl;
}
*/


// ��ӡ16λָ���ַ
/*
string getHex(int x)
{
	char buff[10];
	//sprintf_s() �Ѹ�ʽ��������д��ĳ���ַ���
	sprintf_s(buff, "%X", (x & 0xFFFF)); // (x & 0xFFFF) ����˼�� ȡ16���Ƶ�ַ�ĵ���λ
	return (string)buff; // ǿ��ת�����ַ�������
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
			cout << getHex((int)p); // ��ȡ16���ƺ�4λ
		}
		cout << endl;
	}

	
	int* q[3] = { arr[0],arr[1],arr[2] };
	int(*p)[4];
	p = &arr[0];
	// ����ָ��
	cout << "����ָ��" << endl;
	for (int i = 0; i < 3; ++i)
	{
		string s = getHex((int)(p + i));
		cout << "��" << i << "��[4]����ĵ�ַ��" << s << endl;
	}

	// ָ������
	cout << "ָ�����飨ûɶ�ã�" << endl; 
	for (int i = 0; i < 3; ++i)
	{
		string s = getHex((int)(q + i));  // ����ȡ����&arr[0] �ĵ�ַ ����ָ��
		cout << "��" << i << "��qԪ�صĵ�ַ��" << s << endl;
	}

}
*/


// ָ�뺯��
/*
int* getArray(int a, int d, int n)
{
	int* ret = new int[n]; // ��̬����
	for (int i = 0; i < n; ++i)
	{
		// ����a��i������d
		ret[i] = a + i * d;
	}
	return ret;
}
int main()
{
	//����������׵�ַ ������ָ�����
	int* ans = getArray(5, 4, 10);
	for (int i = 0; i < 10; ++i)
	{
		//*(ans+i)
		cout << ans[i] << ' ';
	}
	return 0;
}
*/

// ָ�뺯�����Ͷ���
// typedef ����ָ�뺯������
/*
typedef void (*ps)(int a, int b, int c );
void fun(int a, int b, int c)
{
	cout << a << b << c  << endl;
}

// ָ�뺯���������Ͷ���
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
	// ����ָ��
	ps Aps = fun;
	Aps(1, 2, 3);
	ps Bps = fun;
	Bps(2, 3, 4);

	// ����ָ������
	pa psArr = { fn1 ,fn2 ,fn3 };
	return 0;
}
*/

// �ṹ������
/*
struct Book
{
	string name;
	double price;
	int value;
};
int main()
{
	// c++�п���ֱ��д�ṹ���� ʡ��struct
	Book book[3] =
	{
		{"��ѧ",10.22,10},
		{"����",20.22,20},
		{"Ӣ��",30.22,30},
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
			{{9,8},5}, // ÿһ��Circle���͵�����
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
union��ʹ�� �� ���캯����ʼ���ṹ���Ա
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
	//���캯��
	Info(const char name[20], int role, double s, const char c[20])
	{
		strcpy_s(_name, name);
		_role = role;
		if (s > 0)
		{
			// ��Ϊ������ͬ����Ҫ��_scȥ��ȡ
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
		Info("����ʦ",0,-1,"C++"),
		Info("����ʦ",0,-1,"Python"),
		Info("��ͬѧ",1,90,""),
		Info("��ͬѧ",1,80,""),

	};
	for (int i = 0; i < 4; ++i)
	{
		if (a[i]._role == 0)
		{
			cout << a[i]._name << "��һλ��ʦ�����̵���" << a[i]._sc.course <<endl;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (a[i]._role == 1)
		{
			cout << a[i]._name << "��һλѧ�������ĳɼ���" << a[i]._sc.score << endl;
		}
	}

	return 0;
}

*/

/*
new �� delete
*/
/*
int main()
{
	// int* ptr = new int(10); ��̬����һ�����ε��ڴ��С ���Ҹ�ֵ10
	// int* ptr = new int[20]; ��̬����20������Ԫ���ڴ��С������ û�г�ʼ��Ԫ�� Ԫ��Ϊ���ֵ
	int* ptr = new int[20]();  // ��̬����20������Ԫ���ڴ��С������ ��ʼ��Ԫ��Ϊ��
	cout << *ptr << endl;
	delete ptr; // �ͷ��ڴ�
	ptr = NULL;
	return 0;
}
*/


/*
�����ڴ�����
*/
/*
// �������������ĵĲ�
int* getGapList(int* arr, int size)
{
	int* ptr = new int[size - 1];
	// ���ﲻ��ʹ�þֲ����� ��Ϊa��ջ�ϵı��� ������Ϊ����ֵ
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
	delete[] ret; // ����[]ֻ��ɾ�� �����һ��Ԫ�� ����ɾ����������
	ret = NULL;
	return 0;
}
*/

/*
����: 1.�����ʼ��
	  2.��ʼ���Ժ��޷��޸�
*/
/*
int main()
{
	//int& a; ����
	int a = 10, c = 6;
	int& b = a; // �൱����a�ı���Ϊb
	b = c; // b = 6 a = 6
	cout << b << a << c;
	return 0;
}
*/


/*
���õı��ʾ���ָ�볣��
*/
/*
int main()
{
	int a = 10;
	// int& b = a;
	// b = 20;

	// �����δ����ǵȼ۵�
	// ���õı���

	int* const b = &a;
	*b = 20;
	return 0;
}
*/

/*
�����ڴ���ʱ������
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
			// ��ָ������ �ı�count��ͬʱ ʵ��Ҳ��ı�
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


