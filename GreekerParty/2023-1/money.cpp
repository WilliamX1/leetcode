#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;


int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    
    int64_t n; cin >> n;
    vector<int64_t> numbers(n);

    for (int64_t i = 0; i < n; i++)
        scanf("%lld", &numbers[i]);

    vector<int64_t> dp_prev(n + 1, -2e18), dp_next;
    dp_prev[0] = 0;
    dp_prev[1] = -numbers[0];

    for (int i = 1; i < n; i++) {
        dp_next = vector<int64_t>(n + 1, -2e18);
        for (int j = 0; j < n; j++) {
            dp_next[j] = max(dp_next[j], dp_prev[j]); // no buy no sell
            if (j > 0) // buy
                dp_next[j] = max(dp_next[j], dp_prev[j - 1] - numbers[i]);
            dp_next[j] = max(dp_next[j], dp_prev[j + 1] + numbers[i]); // sell
        };
        dp_prev = dp_next;
    };
    cout << *max_element(dp_prev.begin(), dp_prev.end()) << endl;


    return 0;
}