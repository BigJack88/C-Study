#include "MemoryPool.h"
#include "SimpleSharedPtr.h"
#include <algorithm>
#include <vector>
#include <functional>
/*
int main()
{
	MemoryPool pool(sizeof(Student), 2);
	auto mem1 = pool.allocate();
	auto stu1 = new(mem1) Student("Tom", 20);
	std::cout << stu1->_name << std::endl;

	SimpleSharedPtr<Student> stu2(new Student("Jenny", 20));
	std::cout << stu2->_name << std::endl;
	SimpleSharedPtr<Student> stu3(stu2);
	std::cout << stu3->_name << std::endl;
	SimpleSharedPtr<Student> stu4(new Student("Jack", 40));
	stu3 = stu4;
	std::cout << stu3->_name << std::endl;
	SimpleSharedPtr<Student> stu5 = std::move(stu3);
	std::cout << stu5->_name << std::endl;
	std::cout << stu5.getCount()<< std::endl;
	std::cout << stu2.getCount() << std::endl;


	int threshold = 5;
	std::vector<int> vec = { 2,4,6,20,30,9,5 };
	auto removeObj = std::remove_if(vec.begin(), vec.end(), [threshold](int x) -> bool
		{
			return x <= threshold;
		});
	vec.erase(removeObj, vec.end());
	
	std::cout << std::endl;
	for (auto &  it : vec)
	{
		std::cout << it << " ";
	}
	std::function<int(int, int)> func1 = [](int a, int b) {
		return a - b;
		};
	std::cout <<  func1(20, 10)  << std::endl;

	return 0;
}
*/

/*
#include "Complex.h"
int main()
{
	Complex com(2.2,3.3);
	Complex com2(1.8, 4.4);
	com = com - com2;
	std::cout << com << std::endl;
	return 0;
}
*/

/*
#include "List.h"
int main()
{
	List<int> myList;
	myList.push_back(10);   // Î²²å
	myList.push_front(20);  // Í·²å

	auto listIter = myList.begin();
	listIter++;
	myList.insert(listIter, 30);  // µü´úÆ÷²åÈë
	for (auto& it : myList)
	{
		std::cout << it << std::endl;
	}

	myList.push_back(40);
	myList.push_back(50);
	myList.remove(40);  // É¾³ýÔªËØ
	myList.pop_back();  // É¾³ýÎ²ÔªËØ
	myList.erase(myList.begin());  // µü´úÆ÷É¾³ý
	for (auto& it : myList)
	{
		std::cout << it << std::endl;
	}
	return 0;
}
*/


#include "practice.h"
int main()
{
	try
	{
		memoryNew memory(sizeof(int), 20);
		void* mem1 = memory.allocate();
		auto student = new(mem1) int(20);
		std::cout << *student << std::endl;
		memory.deallcate(student);
	}
	catch (const std::bad_alloc & e)
	{
		std::cout << "Memory alloction error:" << e.what() << std::endl;
		return 1;
	}
	
	auto single1 = SingleNet::GetInst();
	auto single2 = SingleNet::GetInst();
	std::cout << single1 << std::endl;
	std::cout << single2 << std::endl;




	return 0;
}
