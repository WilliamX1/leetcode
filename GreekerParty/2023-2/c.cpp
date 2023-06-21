#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int n; scanf("%d", &n);
    vector<int64_t> numbers(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &numbers[i]);
    
    if (n == 2) {
        printf("%lld\n", numbers[0] * numbers[1] - numbers[0] - numbers[1]);
    } else {
        printf("0\n");
    }
    
    return 0;
}
        