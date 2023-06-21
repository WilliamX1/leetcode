#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int n; scanf("%d", &n);
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);
    
    int MM = 2e9 + 7;
    vector<int> dp(n + 1, MM);
    dp[0] = -MM;

    int plus = 0;

    for (int& num : numbers) {
        if (num == -1) plus++;
        else {
            num -= plus;
            int pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin() - 1 + 1;
            if (pos) dp[pos] = num;
        };
    };

    int ans = dp.size() - 1;
    while (ans >= 0 && dp[ans] == MM) ans--;
    printf("%d\n", ans + plus);

    return 0;
}
