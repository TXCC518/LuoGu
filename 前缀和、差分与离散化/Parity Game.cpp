#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int fa[2 * N];
vector<int> tmp;

struct node
{
	int x, y;
	string op;
}ans[N];


int get(int u)
{
	int l = -1, r = tmp.size();
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(tmp[mid] < u) l = mid;
		else r = mid;
	}
	return r;
}

int find(int u)
{
	if(fa[u] != u) fa[u] = find(fa[u]);
	return fa[u];
}

void merge(int x, int y)
{
	fa[find(x)] = find(y);
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> ans[i].x >> ans[i].y >> ans[i].op;
		tmp.push_back(ans[i].x);
		tmp.push_back(ans[i].y);
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for(int i = 1;i <= m; i++)
	{
		ans[i].x = get(ans[i].x) + 1;
		ans[i].y = get(ans[i].y) + 1;
	}
	int tol = tmp.size();
	for(int i = 1;i <= 2 * tol; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x = ans[i].x-1, y = ans[i].y;
		string op = ans[i].op;
		if(op == "even")
		{
			if(find(x) == find(y + tol)) 
			{
				cout << i-1 << endl;
				return 0;
			}
			merge(x, y);
			merge(x + tol, y + tol);
		}
		else 
		{
			if(find(x) == find(y))
			{
				cout << i - 1 << endl;
				return 0;
			}
			merge(x, y + tol);
			merge(x + tol, y);
		}
	}
	cout << m << endl;
	
	return 0;
}

