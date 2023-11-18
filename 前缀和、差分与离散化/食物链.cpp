#include <iostream>

using namespace std;

const int N = 5e4 + 10;

int n, k;
int a[3 * N];

int find(int u)
{
	if(a[u] != u) a[u] = find(a[u]);
	return a[u];
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= 3 * n; i++) a[i] = i;
	int res = 0;
	while(k--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if(x > n || y > n)
		{
			res++;
			continue;
		}
		if(t == 1)
		{
			if(find(x) == find(y + n) || find(x) == find(y + n + n)) res++;
			else
			{
				a[find(x)] = a[find(y)];
				a[find(x+n)] = a[find(y+n)];
				a[find(x+n+n)] = a[find(y+n+n)];
			}
		}
		else
		{
			if(x == y || find(x) == find(y) || find(x) == find(y + n)) res++;
			else
			{
				a[find(x)] = find(y + n + n);
				a[find(x + n)] = find(y);
				a[find(x + n + n)] = find(y + n);
			}
		}
	}
	
	cout << res << endl;
	
	return 0;
}
