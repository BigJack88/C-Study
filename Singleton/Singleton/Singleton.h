#include <iostream>
#include <mutex>

template <typename T>
class Singleton
{
protected:
	Singleton() = default;
	Singleton(const Singleton&) = default;
	Singleton& operator=(const Singleton&) = default;
	static std::shared_ptr<T> _single;
public:
	~Singleton() { std::cout << "Singleton is Delete"; };
	static std::shared_ptr<T> GetInst()
	{
		static std::once_flag _flag;
		std::call_once(_flag, []() {
			_single = std::shared_ptr<T>(new T());
		});
		return _single;
	}
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