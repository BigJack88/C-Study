#include "stack"
#include "memory"
#include "mutex"
#include "thread"
#include <iostream>
class memoryNew
{
public:
	memoryNew(const size_t& objectSize, const size_t& objectLength) : _objectSize(objectSize), _objectLength(objectLength)
	{
		_pool = new char[_objectSize * _objectLength];
		for (int i = 0; i < _objectLength; ++i)
		{
			_StackPool.push(_pool + i * _objectSize);
		}
	};
	void* allocate()
	{
		if (_StackPool.empty()) throw std::bad_alloc();
		void* mem = _StackPool.top();
		_StackPool.pop();
		return mem;
	};
	void deallcate(void * ptr)
	{
		/*if (sizeof(ptr) != _objectSize) throw std::bad_alloc(); 需要处理 归还的内存和借出的内存是否一致的问题 */ 
		_StackPool.push(ptr);
	};
	~memoryNew()
	{
		delete[]_pool;
	};
private:
	size_t _objectSize;
	size_t _objectLength;
	char* _pool;
	std::stack<void*> _StackPool;
	memoryNew() = delete;
};


template <typename T>
class Singleton
{
protected:
	Singleton() = delete;
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static std::shared_ptr<T> _single;
public:
	static std::shared_ptr<T> GetInst()
	{
		static std::once_flag _flag;
		std::call_once(_flag, []() {
			_single = std::shared_ptr<T>(new T());
		});
		return _single;
	};
	~Singleton() { std::cout << "Singleton is Delete" << std::endl; };
};

template <typename T>
std::shared_ptr<T> Singleton<T>::_single = nullptr;


class SingleNet : public Singleton<SingleNet>
{
	friend class Singleton<SingleNet>;
private:
	SingleNet() = default;
public:
	~SingleNet() { std::cout << "SingleNet is Delete" << std::endl; };
	
};










