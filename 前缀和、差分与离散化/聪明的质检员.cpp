#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int , int> PII;

const int N = 2e5 + 10;

int n, m;		// n个矿石，m个区间
LL s;	// 标准值
int wi[N], vi[N];	// 每个矿石的重量和价值
PII lr[N];	// 存储每个区间的左右端点

LL getSum(int w)
{
	LL tw[N], tv[N];		// 矿石数量和价值的前缀和数组
	memset(tw, 0, sizeof tw);
	memset(tv, 0, sizeof tv);
	for(int i = 1; i <= n; i++)
	{
		if(wi[i] >= w) tw[i] = 1 + tw[i-1], tv[i] = vi[i] + tv[i-1];	// 当前矿石符合条件
		else tw[i] = tw[i-1], tv[i] = tv[i-1];	// 当前矿石不符合条件，不用加上当前矿石数量和价值
	}
	LL sum = 0;	// sum表示每个区间的y值相加，就是Y
	for(int i = 1;i <= m; i++)	// 遍历每一个区间
	{
		PII p = lr[i];
		sum += (tw[p.second] - tw[p.first-1]) * (tv[p.second] - tv[p.first-1]);	// 利用前缀和的性质， 数量 * 价值之和
	}
	
	return sum;
}


int main()
{
	cin >> n >> m >> s;
	int minw = 0x3f3f3f3f, maxw = -1;	// minw表示重量最大值，minw表示重量最小值
	for(int i = 1;i <= n; i++)
	{
		cin >> wi[i] >> vi[i];
		if(wi[i] < minw) minw = wi[i];
		if(wi[i] > maxw) maxw = wi[i];
	}
	for(int i = 1;i <= m; i++) 
	{
		int l, r;
		cin >> l >> r;
		lr[i] = {l, r};
	}
	int l = minw - 1, r = maxw + 2;		// 二分的左右范围，因为W = maxw + 1的结果Y = 0，也是一种情况
	LL sum = 0, res = 0x3f3f3f3f3f3f3f3f;	// sum表示在当前参数W下，Y的值， res维护的是|Y-s|的最小值
	while(l <= r)
	{
		int mid = (l + r >> 1);
		sum = getSum(mid);		// 求Y的函数
		if(sum > s) l = mid + 1;	// Y > s
		else r = mid - 1;	// Y <= s
		sum = llabs(sum - s);	// 求|Y-s|的值
		if(sum < res) res = sum;	// 小于res的话，进行更新
	}
	
	cout << res << endl;
	
	return 0;
}
