
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
	//1. Ĭ�Ϲ���
	vector<int> v1;
	printVector(v1);

	// 2. ��ʼ���б�
	vector <int> v2_1 = { 1,2,3,4,5, };
	printVector(v2_1);
	vector <int> v2_2({ 5,4,3,2,1 });
	printVector(v2_2);

	// 3. ������ʼ��
	vector<int> v3(v2_1.begin(), v2_1.end());
	printVector(v3);

	//4. ȫ0��ʼ�� -- ������Ҫ��ʼ��Ϊ0�ĸ���
	vector<int> v4(10);
	printVector(v4);

	//5. vector<int>������(a,b) , ����a���ռ�Ԫ�أ�Ԫ��ֵΪb
	vector<int> v5(8, 6);
	printVector(v5);

	//6. �������캯��
	vector <int> v6(v4);
	printVector(v6);

	//7. assign��ʼ���͸��� a �� b
	vector<int> v7;
	v7.assign(9,8);
	printVector(v7);

	// vector��ķ�������ָ�� �����ÿ��Ի�ȡ����ֵ
	// end()���������һ��Ԫ�صĺ�һ���ռ�
	cout << "��Ԫ�� " << *v2_1.begin() << endl;
	cout << "ĩβԪ�� " << *(v2_1.end() - 1) << endl;
	cout << "���� " << v2_1.capacity() << endl;
	cout << "��Ԫ�� " << v2_1.front() << endl;
	cout << "ĩβԪ�� " << v2_1.back() << endl;

	return 0;
}

*/