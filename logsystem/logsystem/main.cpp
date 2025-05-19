#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable> // ��������
#include <fstream>
#include <atomic> // ԭ�ӱ���
#include <sstream>
#include <vector>
#include <stdexcept> // �쳣����


// �������� ����������ת�����ַ���
template <typename T>
std::string to_string_helper(T&& args)// ���������ֵ����ֵ����
{
	std::stringstream oss; // �ļ������� ������д������ �����ַ�����ʽ����
	oss << std::forward<T>(args);// ԭ��ת��������ԭ������ֵ����ֵ��������
	return oss.str();
}

class logQueue
{
public:
	void push(const std::string& msg) // �ַ���д�����
	{
		
	}
	bool pop(std::string& msg); // �ַ����Ӷ���ȡ��
	void shutdown();	// �رն���
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