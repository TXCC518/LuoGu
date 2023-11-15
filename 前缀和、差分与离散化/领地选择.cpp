#include <iostream>

using namespace std;

const int N = 1005;
int ans[N][N];
int n, m, c;

int main()
{
	cin >> n >> m >> c;
	for(int i = 1;i <= n; i++)
	{
		for(int j = 1; j <= m; j++) cin >> ans[i][j];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			ans[i][j] += ans[i][j-1] + ans[i-1][j] - ans[i-1][j-1];
		}
	}
	int res = -0x3f3f3f3f;
	int x = 0, y = 0;
	for(int i = 1;i + c - 1 <= n; i++)
	{
		for(int j = 1;j + c - 1 <= m; j++)
		{
			int t = ans[i+c-1][j+c-1] - ans[i+c-1][j-1] - ans[i-1][j+c-1] + ans[i-1][j-1];
			if(t > res)
			{
				res = t;
				x = i, y = j;
			}
		}
	}
	cout << x << " " << y << endl;
	
	return 0;
}
