#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n; scanf("%d", &n);
    int a, sum = 0;
    while(n--){
        scanf("%d", &a);
        while(a)
        {
            if (a & 1)
                sum++;
            a >>= 1;
        }
    }

    return 0;
}
