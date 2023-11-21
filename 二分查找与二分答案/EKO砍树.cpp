#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int ans[N];

bool check(int u)
{
	long long res = 0;
	for(int i = 1;i <= n; i++)
	{
		res += (ans[i] - u) > 0 ? (ans[i] - u) : 0;
	}
	if(res >= m) return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> ans[i];
	sort(ans + 1, ans + n + 1);
	int tree = ans[n];
	int l = -1, r = tree + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;
	
	return 0;
}
