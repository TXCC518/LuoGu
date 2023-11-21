#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n, c; 
int ans[N];

int find1(int u, int r)
{
	int l = -1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(ans[mid] <= u) l = mid;
		else r = mid;
	}
	return l;
}

int find2(int u, int r)
{
	int l = -1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(ans[mid] < u) l = mid;
		else r = mid;
	}
	return r;
}

int main()
{
	cin >> n >> c;
	for(int i = 0;i < n; i++) cin >> ans[i];
	sort(ans, ans + n);
	long long res = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		int a = ans[i];
		if(c >= a) break;
		int b = a - c;
		int r = find1(b, i), l = find2(b, i);
		if(ans[l] == b) res += r - l + 1;
	}
	cout << res << endl;
	
	return 0;
}
