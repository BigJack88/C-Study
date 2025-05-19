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
	// 返回值是T& 才能作为左值
	bst[150] = "Denny";
	std::cout << bst[150] << std::endl;

	//lower_bound(key) 返回第一个大于等于 key 的元素的迭代器。
	//upper_bound(key) 返回第一个严格大于 key 的元素的迭代器
	auto itBegin = bst.lower_bound(130);
	auto itEnd = bst.upper_bound(165); // 这里实际上返回的是170
	for (auto it = itBegin; it != itEnd; ++it) //打印出165 是因为迭代器打印会将170之前的所有值打印出来
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}

	return 0;
}