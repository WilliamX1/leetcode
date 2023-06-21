# include <iostream>
# include <stdio.h>
# include <vector>

using namespace std;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int64_t n;
    scanf("%lld", &n);

    int64_t ans = 0;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 4; j++) {
            int64_t remain = n - i - j;
            if (remain < 0) continue;
            else if (remain == 0) ans++;
            else {
                if (remain & 1) {
                    ans += ((remain / 5) + 1) / 2;
                } else {
                    ans += (remain / 5) / 2 + 1;
                };
            };
        };
    };
    printf("%lld\n", ans);

    return 0;
}
