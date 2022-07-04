#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> get_partition(int X, int N)
{
    if (X <= N)
        return {X};
    else
    {
        vector<int> ans = get_partition(X - N, N - 1);
        ans.push_back(N);
        return ans;
    };
}

int main()
{
    int T, N, X, Y;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        scanf("%d%d%d", &N, &X, &Y);
        int tot = N * (N + 1) / 2;
        if (tot % (X + Y))
            printf("Case #%d: IMPOSSIBLE\n", i);
        else
        {
            printf("Case #%d: POSSIBLE\n", i);
            vector<int> ans = get_partition(tot / (X + Y) * X, N);
            printf("%d\n", ans.size());
            for (const int &num : ans)
                printf("%d ", num);
            printf("\n");
        };
    };
    return 0;
}