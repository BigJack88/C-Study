#include <iostream>
using namespace std;

/*
输入：t行数据 每行数据输入6个整数 代表两个时间
输出：t行数据 每行数据是两个时间之和 按60进位
*/

/*
int main()
{
	int t;
	int ah, am, as;
	int bh, bm, bs;
	cin >> t;
	while (t--)
	{
		cin >> ah >> am >> as;
		cin >> bh >> bm >> bs;

		as += bs;
		am += bm;
		ah += bh;

		// 按60进位 并且加给am
		am += as / 60;
		// 进位后 处理as
		as %= 60;

		ah += am / 60;
		am %= 60;

		cout << ah << ' ' << am << ' ' << as  << endl;

	}
	return 0;
}
*/

/*
int main()
{
	int n,ret;
	int sum = 0;
	// 只要cin 不是非法输入就可以一直循环
	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> ret;
			sum += ret;
		}
		cout << sum;
	}
	return 0;
}
*/

/*
定义：f(A)=1,f(a)=-1,f(B)=2,f(b)=-2......f(Z)=26,f(z)=-26
输入：输入一个t代表t组数据 每组数据一个字符x和整数y
输出：每组数据输入f(x)+y的值
*/

/*
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char str[3];
		int y;
		char x;
		int ans = 0;
		cin >> str;
		cin >> y;
		x = str[0];
		if (x >= 'A' && x <= 'Z')
		{
			ans = y + (x - 'A' + 1);
		}
		else if (x >= 'a' && x <= 'z')
		{
			ans = y - (x - 'a' + 1);
		}
		else
		{

		}
		cout << ans << endl;
	}
	return 0;
}
*/

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << '+';
		for (int i = 0; i < n; ++i)
		{
			cout << '-';
		}
		cout << '+' << endl;

		for (int i = 0; i < m; ++i)
		{
			cout << '|';
			for (int j = 0; j < n; ++j)
			{
				cout << ' ';
			}
			cout << '|' << endl;
		}



		cout << '+';
		for (int i = 0; i < n; ++i)
		{
			cout << '-';
		}
		cout << '+' << endl;
	}
	return 0;
}