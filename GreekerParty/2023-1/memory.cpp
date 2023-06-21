#include<iostream>
#include <stdio.h>

using namespace std;

int64_t gcd(int64_t x, int64_t y)
{	
	int64_t z = y;
	while(x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;	
	}
	return z;
}

int64_t lcm(int64_t x, int64_t y)
{
    return x * y / gcd(x, y);
}

int main()
{
    freopen("memory.in","r",stdin);
    freopen("memory.out","w",stdout);

    int64_t a, m, b, n;
    
    scanf("%lld %lld %lld %lld", &a, &m, &b, &n);

    int64_t total_length = lcm(a, b * n);
    int64_t total_spin = total_length / a;
    int64_t total_spin2 = total_length / b;
    int64_t no_spin = total_length / lcm(a, b);

    // cout << total_length << " " << total_spin << " " << total_spin2 << " " << no_spin << endl;

    int64_t ans = total_spin + total_spin2 - no_spin;
    printf("%lld", ans);
    return 0;
}