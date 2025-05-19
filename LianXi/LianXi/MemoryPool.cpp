#include "MemoryPool.h"

MemoryPool::MemoryPool(size_t objSize, size_t totalSize) :_objSize(objSize), _totalSize(totalSize)
{
	_pool = new char[_objSize * _totalSize];
	if (_pool == nullptr) throw std::bad_alloc();
	for (int i = 0; i < _totalSize; ++i)
	{
		_poolList.push(_pool + i * _objSize);
	}
}
MemoryPool::~MemoryPool()
{
	delete[]_pool;
}
void* MemoryPool::allocate()
{
	if (_poolList.empty()) throw std::bad_alloc();
	void* ptr = _poolList.top();
	_poolList.pop();
	return ptr;
}
void MemoryPool::deallcate(void * ptr)
{
	_poolList.push(ptr);
}