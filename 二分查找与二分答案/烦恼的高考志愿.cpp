#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int m, n;
int a[N], b[N];

int main()
{
	cin >> m >> n;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	sort(a+1, a+m+1);
	int res = 0;
	for(int i = 1;i <= n;i ++)
	{
		int l = 0, r = m + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(a[mid] <= b[i]) l = mid;
			else r = mid;
		}
		int t = abs(a[l] - b[i]);
		l = 0, r = m + 1;
		while(l + 1 != r)
		{
			int mid = l + r >> 1;
			if(a[mid] < b[i]) l = mid;
			else r = mid;
		}
		t = min(t, abs(a[r] - b[i]));
		res += t;
	}
	cout << res << endl;
	
	return 0;
}
