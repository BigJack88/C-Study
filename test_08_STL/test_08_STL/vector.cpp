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
	// ����
	v1.insert(v1.begin()+2, 888);
	printVector(v1, "v1");
	insert(v2.end(),v2.begin(),v2.end()) // ��Χ����(����λ�ã����Ŀ�ʼ�����Ľ���)

	// ɾv1��
	v1.pop_back();
	printVector(v1, "v1");
	vector<int>::iterator item = v1.erase(v1.begin()+1); // erase����ʹ��begin()��end()
	printVector(v1, "v1");
	cout << *item << endl; // ����������ɾ��Ԫ�صĺ�һ��Ԫ��

	//��� -- ���size() ����capacity()��Ȼռ���ڴ�
	// v1.clear(); 
	// printVector(v1,"v1");

	// ����������Ԫ��
	// cout << v1.at(12) << endl; // Խ�����ʾ�쳣
	// cout << v1[12] << endl; // Խ�粻����ʾ�쳣 - ��Ч�ʸ�


	// ���� -- �ı�size�Ĵ�С ���size����capacity �����1.5������
	v1.resize(200);  
	cout << "v1:" << v1.size() << endl;
	cout << "v1:" << v1.capacity() << endl;
	printVector(v1, "v1");
	cout << endl;

	// ����
	v1.resize(5);
	// �������캯����size��ֵ��capacity���
	// ʹ������������������v1 ��ʱ����������capacity��ֵ�Ѿ��ص� �ٵ���swap��������v1�ĵ�ַ
	vector<int>(v1).swap(v1); 
	cout << "v1:" << v1.size() << endl;
	cout << "v1:" << v1.capacity() << endl;
	printVector(v1, "v1");
	cout << endl;

	//***�ڴ�����
	v1.resize(10000);
	vector<int>({}).swap(v1);
	cout << "v1:" << v1.size() << endl;
	cout << "v1:" << v1.capacity() << endl;
	printVector(v1, "v1");
	cout << endl;

	//�ռ�Ԥ��
	vector<int> v2;
	v2.reserve(100); // �޸�capacity��ֵ
	for (int i = 0; i < 100; i++)
	{
		//����֪Ҫ���ٿռ��Сʱ ��ǰ�޸�capacity��ֵ��������Ч��
		v2.push_back(i);
	}
	cout << "v2:" << v2.size() << endl;
	cout << "v2:" << v2.capacity() << endl;
	printVector(v2, "v2");

	//��ȡvector��������Сֵ ���ص�ַ
	int maxPosition = max_element(n.begin(),n.end()) - n.begin(); //���ֵ�±�

	int minPosition = min_element(n.begin(),n.end()) - n.begin();//��Сֵ�±�

	2����ͨ����
	int a[]={1,2,3,4};
	int maxPosition = max_element(a,a+2) - a; //���ֵ�±�

	int minPosition = min_element(a,a+2) - a;//��Сֵ�±�

	// ����ȥ��
	// unique���ظ�Ԫ���ƶ��������ĩβ ���ҷ���һ���Ƴ�������ʼ��Χ�ĵ�����
	// �ٵ���eraseɾ��
	v.erase(unique(v.begin(), v.end()), v.end());
	return 0;
}
*/