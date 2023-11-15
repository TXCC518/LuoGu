#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
int n;
vector<int> ans, res;
vector<PII> lr;

int find(int u)
{
	int l = -1, r = ans.size();
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
	cin >> n;
	while(n--)
	{
		int a, b;
		cin >> a >> b;
		ans.push_back(a), ans.push_back(b);
		lr.push_back({a, b});
	}
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	sort(ans.begin(), ans.end());
	int res[ans.size() + 10];
	memset(res, 0, sizeof res);
	for(int i = 0;i < lr.size();i ++)
	{
		PII p = lr[i];
		int l = find(p.first), r = find(p.second);
		res[l + 1] += 1;
		res[r + 1] -= 1;
	}
	int cnt = 0;
	for(int i = 1; i <= ans.size(); i++)
	{
		res[i] += res[i-1];
	}
	for(int i = 1;i <= ans.size();i ++)
	{
		int t = i;
		while(res[i] > 0) i++;
		cnt += (ans[i-1] - ans[t-1]);
	}
	cout << cnt << endl;
	
	return 0;
	
}
