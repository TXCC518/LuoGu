#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int ans[N];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n; i++) scanf("%d", &ans[i]);
	while(m--)
	{
		int u = 0;
		cin >> u;
		int l = 0, r = n + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(ans[mid] < u) l = mid;
			else r = mid;
		}
		printf("%d ", ans[r] == u ? r : -1);
	}
	
	return 0;
}
