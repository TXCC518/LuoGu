#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int t, n;
vector<int> a, book;

struct node
{
	int i, j, e;
}tol[N];

bool cmp(node a, node b)
{
	return a.e > b.e;
}

int find(int u)
{
	if(book[u] != u) book[u] = find(book[u]);
	return book[u];
}

int get(int u)
{
	int l = -1, r = a.size();
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(a[mid] < u) l = mid;
		else r = mid;
	}
	return r;
}

int main()
{
	cin >> t;
	while(t--)
	{
		a.clear();
		memset(tol, 0, sizeof tol);
		cin >> n;
		int flag = true;
		for(int k = 0; k < n; k++)
		{
			int i, j, e;
			cin >> i >> j >> e;
			tol[k] = {i, j, e};
			a.push_back(i);
			a.push_back(j);
		}
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		sort(tol, tol+n, cmp);
		book.clear();
		for(int i = 0; i < a.size();i ++) book.push_back(i);
		for(int k = 0; k < n; k++)
		{
			int i = tol[k].i, j = tol[k].j, e = tol[k].e;
			i = get(i), j = get(j);
			if(e == 1) book[find(i)] = find(j);
			else 
			{
				if(find(i) == find(j)) flag = false;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
