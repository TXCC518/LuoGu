#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, m;

int main()
{
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 1;i <= n;i ++) a[i] += a[i-1];
	cin >> m;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l-1] << endl;
	}
	
	return 0;
}
