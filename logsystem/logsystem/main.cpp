#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable> // 条件变量
#include <fstream>
#include <atomic> // 原子变量
#include <sstream>
#include <vector>
#include <stdexcept> // 异常处理


// 辅助函数 将单个参数转换成字符串
template <typename T>
std::string to_string_helper(T&& args)// 允许接受左值和右值引用
{
	std::stringstream oss; // 文件流对象 将数据写入流中 并以字符串形式返回
	oss << std::forward<T>(args);// 原样转发，保持原来的左值或右值引用属性
	return oss.str();
}

class logQueue
{
public:
	void push(const std::string& msg) // 字符串写入队列
	{
		
	}
	bool pop(std::string& msg); // 字符串从队列取出
	void shutdown();	// 关闭队列
private:
	std::queue<std::string> queue_;
	std::mutex mutex_;
	std::condition_variable cond_;
	bool is_shutDown_ = false;
};



int main()
{

	return 0;
}