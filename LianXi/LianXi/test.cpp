#include <iostream>
using namespace std;

/*
���룺t������ ÿ����������6������ ��������ʱ��
�����t������ ÿ������������ʱ��֮�� ��60��λ
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

		// ��60��λ ���ҼӸ�am
		am += as / 60;
		// ��λ�� ����as
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
	// ֻҪcin ���ǷǷ�����Ϳ���һֱѭ��
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
���壺f(A)=1,f(a)=-1,f(B)=2,f(b)=-2......f(Z)=26,f(z)=-26
���룺����һ��t����t������ ÿ������һ���ַ�x������y
�����ÿ����������f(x)+y��ֵ
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