#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
typedef long long LL;

int n, m;
int ri[N];
LL tmp[N];
int di[N], si[N], ti[N];

int solve(int u)
{
	memset(tmp, 0, sizeof tmp);
	for(int i = 1; i<= u; i++)
	{
		tmp[si[i]] += di[i];
		tmp[ti[i] + 1] -= di[i];
	}
	for(int i = 1;i <= n; i++)
	{
		tmp[i] += tmp[i-1];
		if(tmp[i] > ri[i]) return 0;
	}
	return 1;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> ri[i];
	for(int i = 1;i <= m; i++) cin >> di[i] >> si[i] >> ti[i];
	if(solve(m)) 
	{
		cout << 0 << endl;
		return 0;
	}
	int l = 0, r = m + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(solve(mid)) l = mid;
		else r = mid;
	}
	cout << -1 << endl;
	cout << r << endl;
	
	return 0;
}
