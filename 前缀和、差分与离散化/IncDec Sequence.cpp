#include <iostream>

using namespace std;

const int N = 1e5 + 10;

long long a[N];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		long long t;
		cin >> t;
		a[i] += t, a[i+1] -= t;
	}
	long long sum1 = 0, sum2 = 0;
	for(int i = 2;i <= n;i ++)
	{
		if(a[i] < 0) sum1 -= a[i];
		else if(a[i] > 0) sum2 += a[i];
	}
	cout << max(sum1, sum2) << endl;
	cout << abs(sum1 - sum2) + 1 << endl;
	
	return 0;
	
}
