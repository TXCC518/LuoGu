#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int trees[N];
int n, k;

int check(int l)
{
	int num = 0;
	for(int i = 1;i <= n; i++)
	{
		num += trees[i] / l;	
	}
	if(num >= k) return 1;
	return 0;
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n;i ++) cin >> trees[i];
	sort(trees + 1, trees + n + 1);
    int l = 0, r = trees[n] + 1;
	while(l + 1 != r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;
	
	return 0;
}
