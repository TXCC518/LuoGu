#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int N = 50010;
map<int, int> a;	// 将ID编号离散化成一串连续的编号
int c[N];	// 下标为编号，出现了多少次
int nums;	// 牛的种类
int n;

struct node
{
	int x, id;
}niu[N], q[N];

bool cmp(node a, node b)
{
	return a.x < b.x;
}

int main()
{
	cin >> n;
	for(int i = 0;i < n;i ++)
	{
		int id;
		cin >> niu[i].x >> id;
		if(!a.count(id))
		{
			nums++;
			a[id] = nums;
		}
		niu[i].id = a[id];
	}
	sort(niu, niu + n, cmp);
	int hh = 0, tt = 0;
	int res = 0;
	q[tt] = {niu[0].x, niu[0].id};
	res++;
	int ress = 0x3f3f3f3f;
	c[niu[0].id]++;
	while(hh <= tt)
	{
		while(c[q[hh].id] > 1)
		{
			c[q[hh].id]--;
			hh++;
		}
		if(res == nums)
		{
			ress = min(ress, q[tt].x - q[hh].x);
		}
		if(tt == n-1) break;
		if(tt < n-1)
		{
			q[++tt] = {niu[tt].x, niu[tt].id};
			if(c[niu[tt].id] == 0) res++;
			c[niu[tt].id]++;
		}
	}
	cout << ress << endl;
	
	return 0;
}

