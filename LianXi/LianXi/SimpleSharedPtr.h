#pragma once
#include <iostream>
struct ControlBlock
{
	int ref_conut;
	ControlBlock() :ref_conut(1) {};
};

template <typename T>
class SimpleSharedPtr
{
private:
	T* _ptr;
	ControlBlock* _block;
public:
	SimpleSharedPtr() : _ptr(nullptr), _block(nullptr) {};
	SimpleSharedPtr(T* ptr)
	{
		_ptr = ptr;
		if (_ptr)
		{
			_block = new ControlBlock();
		}
		else
		{
			_block = nullptr;
		}

	};
	void release()
	{
		if (_block)
		{
			--_block->ref_conut;
			if (_block->ref_conut == 0)
			{
				delete _ptr;
				_ptr = nullptr;
				delete _block;
				_block = nullptr;
			}
		}
	}
	SimpleSharedPtr(const SimpleSharedPtr& other)
	{
		if (this == &other) throw std::bad_alloc();
		_ptr = other._ptr;
		_block = other._block;
		if (_ptr) ++_block->ref_conut;
	}
	SimpleSharedPtr& operator=(const SimpleSharedPtr& other)
	{
		if (this != &other)
		{
			release();
			_ptr = other._ptr;
			_block = other._block;
			if (_ptr) ++_block->ref_conut;
		};
		return *this;
	}
	SimpleSharedPtr(SimpleSharedPtr&& other) noexcept:_ptr(other._ptr),_block(other._block)
	{
		other._ptr = nullptr;
		other._block = nullptr;
	}
	SimpleSharedPtr&& operator=(SimpleSharedPtr&& other)
	{
		if (this != &other)
		{
			release();
			_ptr = other._ptr;
			_block = other._block;
			other._ptr = nullptr;
			other._block = nullptr;
		};
		return *this;
	}
	~SimpleSharedPtr()
	{
		if (_ptr) release();
	}
	void reset(T * ptr)
	{
		release();
		_ptr = ptr;
		if (_ptr)
		{
			_block = new ControlBlock();
		}
		else
		{
			_block = nullptr;
		}
	}
	int getCount() const
	{
		return _block ? _block->ref_conut : 0;
	}
	T* operator->() const
	{
		return _ptr;
	}
	T* operator*() const
	{
		return _ptr;
	}
};



