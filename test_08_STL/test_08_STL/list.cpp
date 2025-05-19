#include "include.h";

void printList(const list<int>& v, string str)
{
	cout << str << ":";
	for (list<int>::const_iterator item = v.begin(); item != v.end(); item++)
	{
		cout << *item << ' ';
	}
	cout << endl;
}

int main()
{
	return 0;
}