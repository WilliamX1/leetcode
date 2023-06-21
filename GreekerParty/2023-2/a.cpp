# include <iostream>
# include <stdio.h>
# include <vector>

using namespace std;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int64_t T, X, Y;
    scanf("%lld", &T);

    while (T--) {
        scanf("%lld %lld", &X, &Y);
        int64_t minus = X - 2 * Y;
        if (minus >= 0ll && !(minus & Y))
            printf("Yes\n"); 
        else printf("No\n");
    }
    return 0;
}
