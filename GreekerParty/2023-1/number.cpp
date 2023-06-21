#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int n; scanf("%d", &n);
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    int m = *max_element(numbers.begin(), numbers.end());
    int mod = 19260817, ans = 0, base = m, tmp = 0;

    vector<unordered_map<int, int>> forward(m + 1);
    unordered_map<int, int> forward_count;

    unordered_set<int> forward_set;
    for (const int& num : numbers) {
        forward_count[num]++;

        tmp = forward[num][0 + base] + 1;
        ans += tmp;
        forward[num][0 + base] = (forward[num][0 + base] + tmp) % mod;

        for (const int& last : forward_set)
            if (num != last) {
                tmp = forward[last][num - last + base] + forward_count[last];
                forward[num][num - last + base] = (forward[num][num - last + base] + tmp) % mod;
                ans = (ans + tmp) % mod;
            }
        forward_set.insert(num);
    };

    printf("%d\n", ans);

    return 0;
}