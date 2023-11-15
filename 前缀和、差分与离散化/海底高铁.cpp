#include <iostream>

using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL ans[N], tmp[N];
int ai[N], bi[N], ci[N];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= m; i++) cin >> ans[i];
	for(int i = 1;i < m; i++)
	{
		int l = min(ans[i], ans[i+1]);
		int r = max(ans[i], ans[i+1]);
		tmp[l]++;
		tmp[r]--;
	}
	for(int i = 1;i < n; i++) tmp[i] += tmp[i-1];
	for(int i = 1; i <= n; i++)
	{
		cin >> ai[i] >> bi[i] >> ci[i];
	}
	LL sum = 0;
	for(int i = 1; i < n; i++)	
	{
		LL sum1 = ai[i] * tmp[i];
		LL sum2 = bi[i] * tmp[i] + ci[i];
		sum += min(sum1, sum2);
	}
	
	cout << sum << endl;
	
	return 0;
}
