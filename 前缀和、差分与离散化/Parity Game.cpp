//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//const int N = 1e4 + 10;
//
//int fa[2 * N];		// 两个扩展域：1~N表示偶数关系，N+1~2N表示奇数关系
//int n, m;
//vector<int> ans;	// 离散化数组
//
//struct node
//{
//	int x, y;
//	string op;
//}a[N];
//
//int get(int u)
//{
//	int l = 0, r = ans.size();
//	while(l + 1 != r)
//	{
//		int mid = l + r >> 1;
//		if(ans[mid] < u) l = mid;
//		else r = mid;
//	}
//	return r;
//}
//
//int find(int u)
//{
//	if(fa[u] != u) fa[u] = find(fa[u]);
//	return fa[u];
//}
//
//void merge(int x, int y)
//{
//	fa[find(x)] = find(y);
//}
//
//int main()
//{
//	cin >> n >> m;
//	for(int i = 1; i <= m; i++)
//	{
//		cin >> a[i].x >> a[i].y >> a[i].op;
//		a[i].x--;
//		ans.push_back(a[i].x);
//		ans.push_back(a[i].y);
//	}
//	sort(ans.begin(), ans.end());
//	ans.erase(unique(ans.begin(), ans.end()), ans.end());
//	ans.insert(ans.begin(), 0);
//	for(int i = 1;i <= m; i++)
//	{
//		a[i].x = get(a[i].x);
//		a[i].y = get(a[i].y);
//	}
//	for(int i = 0;i < 2 * N; i++) fa[i] = i;
//	n = ans.size();
//	for(int i = 1; i <= m; i++)
//	{
//		int x = a[i].x, y = a[i].y;
//		string op = a[i].op;
//		if(op == "even")
//		{
//			if(find(x) == find(y + n))
//			{
//				cout << i - 1 << endl;
//				return 0;
//			}
//			merge(x, y); 
//			merge(x + n, y + n);
//		}
//		else
//		{
//			if(find(x) == find(y))
//			{
//				cout << i - 1 << endl;
//				return 0;
//			}
//			merge(x, y + n);
//			merge(x + n, y);
//		}
//	}
//	cout << m << endl;
//	
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int fa[N];
int d[N];
vector<int> ans;
int n, m;

struct node
{
	int x, y;
	string op;
}a[N];

int get(int u)
{
	int l = 0, r = ans.size();
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(ans[mid] < u) l = mid;
		else r = mid;
	}
	return r;
}

int find(int u)
{
	if(fa[u] != u)
	{
		int t = find(fa[u]);
		d[u] += d[fa[u]];
		fa[u] = t;
	}
	return fa[u];
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= m; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].op;
		a[i].x--;
		ans.push_back(a[i].x);
		ans.push_back(a[i].y);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	ans.insert(ans.begin(), 0);
	for(int i = 1; i <= m; i++) 
	{
		a[i].x = get(a[i].x);
		a[i].y = get(a[i].y);
	}
	for(int i = 1; i <= ans.size(); i++) fa[i] = i;
	for(int i = 1;i <= m; i++)
	{
		int fx = find(a[i].x), fy = find(a[i].y);
		string op = a[i].op;
		if(op == "even")
		{
			if(fx != fy)
			{
				d[fx] = d[a[i].x] ^ d[a[i].y];
				fa[fx] = fy;
			}
			else 
			{
				if((d[a[i].x] + d[a[i].y]) % 2 != 0)
				{
					cout << i - 1 << endl;
					return 0;
				}
			}
		}
		else
		{
			if(fx != fy)
			{
				d[fx] = d[a[i].x] ^ d[a[i].y] ^ 1;
				fa[fx] = fy;
			}
			else
			{
				if((d[a[i].x] + d[a[i].y]) % 2 == 0)
				{
					cout << i - 1 << endl;
					
					return 0;
				}
			}
		}
	}
	cout << m << endl;
	
	return 0;
}
