#include "BstMap.h"

int main()
{
	BstMap<int,std::string> bst;
	bst.insert(150,"Tonny");
	bst.insert(130,"June");
	bst.insert(170,"Jack");
	bst.insert(165,"Tom");
	bst.insert(140,"Yong");

	for (auto it = bst.begin(); it != bst.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << "=================" << std::endl;

	bst.erase(150);
	for (auto it = bst.begin(); it != bst.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << "=================" << std::endl;
	// ����ֵ��T& ������Ϊ��ֵ
	bst[150] = "Denny";
	std::cout << bst[150] << std::endl;

	//lower_bound(key) ���ص�һ�����ڵ��� key ��Ԫ�صĵ�������
	//upper_bound(key) ���ص�һ���ϸ���� key ��Ԫ�صĵ�����
	auto itBegin = bst.lower_bound(130);
	auto itEnd = bst.upper_bound(165); // ����ʵ���Ϸ��ص���170
	for (auto it = itBegin; it != itEnd; ++it) //��ӡ��165 ����Ϊ��������ӡ�Ὣ170֮ǰ������ֵ��ӡ����
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}

	return 0;
}