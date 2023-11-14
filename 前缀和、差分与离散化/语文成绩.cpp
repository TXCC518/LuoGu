#include <iostream>

using namespace std;

const int N = 5e6 + 10;

int n, p;
int a[N];

void add(int l, int r, int d)
{
	a[l] += d;
	a[r+1] -= d;
}

int main()
{
	cin >> n >> p;
	for(int i = 1;i <= n; i++)
	{
		int t;
		cin >> t;
		add(i, i, t);
	}
	while(p--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	for(int i = 1;i <= n; i++) a[i] += a[i-1];
	
	int res = 0x3f3f3f3f;
	for(int i = 1;i <= n; i++) res = min(res, a[i]);
	
	cout << res << endl;
	
	return 0;
}
