#include <iostream>
using namespace std;

#define eleType double

struct SequentialList
{
	eleType* elements;
	int size; // ����Ԫ�ظ���
	int capacity; // ����
};

// ��ʼ�� 
void initializeList(SequentialList* list, int capacity)
{
	list->elements = new eleType[capacity];
	list->size = 0;
	list->capacity = capacity;
}
// ����
void destroyList(SequentialList* list)
{
	delete[]list->elements;
}
// ��ȡsize
int getSize(SequentialList* list)
{
	return list->size;
}
// �ж������Ƿ�Ϊ��
bool isEmpty(SequentialList* list)
{
	return list->size == 0;
}
// ����
void Insert(SequentialList* list, int index, eleType element)
{
	// �ж��±��Ƿ�Ϸ�
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

// ɾ��
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
	// �����ɾ�����һ��Ԫ�صĻ��򲻻�ѭ��ֱ��size--
	// ����ʲ������Ԫ���� 
	list->size--;
}

// ��������ֵ
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
// ����ֵ��ͬ��Ԫ�� 
eleType FindElement(SequentialList* list, int index)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");
	}
	return list->elements[index];
}
// �޸Ķ�Ӧ���±��Ԫ��
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
vector˳���
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
//ͳ��������������
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
		
			// ����������� С��1e-8�Ͳ���Ϊ����
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
 ȥ��Сֵ ��ƽ����
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
����������Ԫ�ص����˻�
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
				 // ����maxIndex��ֵ��0 �� subIndex�ĳ�ʼֵ����maxIndex��ֵ��ͬ
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

// forѭ����˫��forѭ����˳��������
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
	// ö��iֵ�ұߵ�Ԫ��
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
	// ö��iֵ��ߵ�Ԫ��
	// ������ 01 012 0123 01234
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << arr[j];
		}
		cout << ' ';
	}
	cout << endl;
	// ���� �ҵ������м���  ʹ�����Ԫ����Ӻ��ұ�Ԫ��������
	for (int i = 0; i < size; ++i)
	{
		int l = 0, r = 0;
		// ö�ٵ�ǰiֵ�����Ԫ��
		for (int j = 0; j < i; ++j)
		{
			l += arr[j];
		}
		// ö�ٵ�ǰiֵ���ұ�Ԫ��
		for (int j = i + 1; j < size; ++j)
		{
			r += arr[j];
		}
		// ����ֵ����򷵻�
		if (l == r)
		{
			
		}
	}
	
	// ����ÿ�ε��� 2 
	// �ж� i �� i + 1�Ĺ�ϵʱ size Ҫ - 1��ֹ����Խ��
	// ���ǵ�����Ԫ������������ʱ ���һ�����Ǽ�ⲻ����
	int ret = 0;
	int i = 0;
	for (i = 0; i < size - 1; i += 2)
	{
		if (arr[i] != arr[i + 1])
		{
			 
		}
	}
	//  if(arr[i])... ����������һ������������ж�;
	
	// �����ұ������� ����Ԫ�ش��ҵ���ݼ�
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


// λ����
/*
	& λ�� ��0��0
*/
/*
int main()
{
	int a = 0b1010; // 10
	int b = 0b0110; // 6
	//a&b = 0b0010 // 2
	cout << "-----" << endl;

	//2.��ż��
	cout << 5 % 2 << endl;	 // ���ȼ��ߣ�Ч�ʵ�
	cout << (5 & 1) << endl; // ���ȼ��ͣ�Ч�ʸ�
	// 0b0101  5 ����������λ���һλ��Զ��1
	// 0b0001  1
	cout << "-----" << endl;

	//3.��ȡһ�����Ķ����ƺ�5λ
	int c = 0b010101011001;
	cout << (c & 0b11111) << endl; // 25
	cout << "-----" << endl;

	//4. ���һ�����Ķ����ƺ�5λ
	int d = 0b01010101;
	cout << (d & 0b111111111111111111111111111100000) << endl;
	cout << "-----" << endl;

	// 5. ��������ĩβ��1
	int e = 0b101111;
	// e+1= 0b110000;
	//      0b100000;
	cout << (e & e + 1) << endl;
	cout << "-----" << endl;

	// 6.�ж��Ƿ���2����
	int f = 0b100000;
	// f-1= 0b011111 = 0
	f > 0 && (f & (f - 1)) == 0;


	return 0;
}
*/


/*
	| λ�� ��1��1
*/
/*
int main()
{
	int a = 0b10110;
	int b = 0b11100;
	//      0b11110
	cout << (a | b) << endl;

	//1. ���ñ�־λ
	int c = 0b10101;
	//      0b11101
	cout << (c | 0b01000) << endl;

	//2. ��ձ�־λ
	int d = 0b10111;
	int m = 0b00001;// ħ��λ ��d��ħ��λû��1ʱ ����1 �����
	//      0b10110
	cout << ((d | m) - m ) << endl;

	// 3. ��λ������0 �� 1
	int e = 0b101100;
	cout << (e | e-1) << endl;

	return 0;
}
*/

/*
	^ ȫ1��0
*/
/*
int main()
{
	// �κ��� ^0 ����������
	// ������ͬ���� ^ ���� 0
	// ��򣺾��ǲ�����λ�Ķ����Ƽӷ�
	int a = 0b00010;
	int b = 0b00101;
	cout << (a ^ b) << endl;

	//1. ���λȡ��
	int c = 0b10110;
	cout << (c ^ 0b100) << endl;
	cout << ((c ^ 0b100) ^ 0b100) << endl;

	//2. ��������
	int d = 17;
	int e = 19;
	d = d ^ e;
	e = d ^ e; // d' ^ e = d^e^e = d ^ 0 = d
	d = d ^ e; // d' ^ d = d^d^e = 0 ^ e = e
	cout << d << ' ' << e << endl;

	//3.���������ε���

	//4. ����
	int x = 1314;
	cout << (x ^ 2933) << endl;

	return 0;
}

*/

/*
	��λȡ�� ~
*/
/*
int main()
{
	int a = 0b000000000000000000000001;
	// 0b111111111111111111111110
	cout << (~a) << endl;

	//2. ���෴�� ~��+1
	int d = 10;
	cout << (~d + 1) << endl;
	//
	return 0;
}
*/

/*
	x << y = x * 2��y�η�
*/

/*
int main()
{
	// ����һλ���ڳ���2
	int x = 0b11; // 3;
	x = (x << 1); // 0b110
	cout << x << endl; // 6

	// ����λ�� �����Ǹ���
	// ����ע�ⲻҪ���
	int a = 64;
	cout << (a<<31) << endl; // 32λ�ض� == 0
	return 0;
}
*/

/*
	x >> y = x / 2��y�η�
*/
/*
int main()
{
	int a = 0b110; //6
	a = (a >> 1);
	cout << a << endl;

	// 2. ��������  ֻ��-1���ƺ����-1 ��������2 
	int b = -2;
	cout << (b >> 1) << endl;

	return 0;
}
*/


/*
��������
����һ������ nums �������е����� Ҫô ����һ�Σ�Ҫô �������Ρ�
���㷵�����������г����������ֵİ�λ XOR ֵ�����û�����ֳ��ֹ����Σ����� 
class Solution {
public:
	int duplicateNumbersXOR(vector<int>& nums) {
		int ans = 0;
		long long visited = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int x = nums[i];
			if (visited & ((long long)1 << x)) // �ж�visited��־λ�Ƿ���1
			{
				ans ^= x;
			}
			else
			{
				// ���û��1���� | ���ѱ�־λ���ó�1
				// 1<<x ��ʾ��1���Ƶ�64λ���������ĵ�xλ ���Ϊ1 
				// ����& ���жϱ�־λ���Ƿ���1
				visited |= ((long long)1 << x);
			}
		}
		return ans;
	}
};
// 0000000000 0000000000 0000000000 0000101000 0000000000
*/
