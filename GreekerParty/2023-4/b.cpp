# include <iostream>
# include <stdio.h>
# include <vector>
# include <algorithm>

using namespace std;

int main()
{
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);

    int64_t n, k;
    cin >> n >> k;

    vector<int64_t> numbers;
    for (int i1 = 0; i1 < k; i1++)
        for (int i2 = 0; i2 < k; i2++)
            for (int i3 = 0; i3 < k; i3++) {
                cout << i1 << " " << i2 << " " << i3 << endl;
                if (i1 == 0 && i2 != 0 || i1 == 0 && i2 == 0 && i3 == 0)
                    continue;
                else
                    numbers.push_back(i1 * 1 + i2 * k + i3 * k * k);
            }
    sort(numbers.begin(), numbers.end());
    cout << numbers.size() << endl;
    for (int i = 0; i < numbers.size(); i++)
        printf("%lld ", numbers[i]);
    cout << endl;

    int64_t size = numbers.size();
    int64_t zeros = ((n - 1) % size) * 2 + 1, remain_k = (n - 1) % size + 1;
    int64_t ans = numbers[remain_k - 1];
    while (zeros--)
        ans *= k;
    cout << ans << endl;

    return 0;
}