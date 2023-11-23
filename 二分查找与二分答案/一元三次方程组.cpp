#include <iostream>

using namespace std;

double a, b, c, d;

double get(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
	cin >> a >> b >> c >> d;
	int s = 0;
	for(double i = -100;i < 100; i++)
	{
		double l = i, r = l + 1;
		double x1 = get(l), x2 = get(r);
		if(!x1)
		{
			printf("%.2lf ", l);
			s++;
		}
		
		if(x1 * x2 < 0)
		{
			while(r - l >= 0.001)
			{
				double mid = (l + r) / 2;
				if(get(mid) * get(r) <= 0) l = mid;
				else r = mid;	
			}
			printf("%.2lf ", r);
			s++;
		}
		
		if(s == 3) break;
	}
	
	return 0;
}
