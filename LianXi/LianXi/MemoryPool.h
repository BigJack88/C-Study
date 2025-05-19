#include <iostream>
#include <stack>
#include <memory>
class MemoryPool
{
private:
	size_t _objSize;
	size_t _totalSize;
	char* _pool;
	std::stack<void*> _poolList;
public:
	MemoryPool() = default;
	MemoryPool(size_t objSize, size_t totalSize);
	~MemoryPool();
	void* allocate();
	void deallcate(void * ptr);
};
