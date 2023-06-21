# include <iostream>
# include <stdio.h>
# include <vector>

using namespace std;

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    
    int64_t n, m, T; scanf("%lld %lld %lld", &n, &m, &T);
    vector<vector<int64_t>> actions;

    int64_t ch, l, r, x;
    while (T--) {
        scanf("%lld", &ch);
        if (ch == 1) {
            scanf("%lld %lld %lld", &l, &r, &x);
            actions.push_back({ch, l, r, x});
        } else if (ch == 2) {
            scanf("%lld %lld", &l, &x);
            actions.push_back({ch, l, x});
        } else if (ch == 3) {
            scanf("%lld %lld", &l, &r);

            int64_t ans = 0;
            int64_t actions_size = actions.size();
            for (int64_t i = actions_size - 1; i >= 0; i--) {
                auto a = actions[i];

                int64_t ch = a[0];
                if (ch == 1) {
                    int64_t ll = a[1], rr = a[2], xx = a[3];
                    if (ll <= r && r <= rr) ans += xx;
                } else if (ch == 2) {
                    int64_t ll = a[1], xx = a[2];
                    if (ll == l) {
                        ans += xx;
                        break;
                    };
                };
                // cout << ans << endl;
            };
            printf("%lld\n", ans);
        };
    };

    return 0;
};