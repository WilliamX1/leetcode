#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        int N, L;
        scanf("%d%d", &N, &L);
        vector<vector<int>> IPD(N, vector<int>(3)), fall_events;
        for (int i = 0; i < N; i++)
        {
            IPD[i][0] = i + 1;
            scanf("%d%d", &IPD[i][1], &IPD[i][2]);

            if (IPD[i][2] == 0) // 左
                fall_events.push_back({IPD[i][1], IPD[i][2]});
            else // 右
                fall_events.push_back({L - IPD[i][1], IPD[i][2]});
        };

        sort(IPD.begin(), IPD.end(), [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

        sort(fall_events.begin(), fall_events.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        int fsize = fall_events.size(), left = 0, right = N - 1;

        printf("Case #%d: ", i);
        for (int i = 0; i < fsize;)
        {
            if (i + 1 < fsize && fall_events[i][0] == fall_events[i + 1][0])
            {
                printf("%d %d ", min(IPD[left][0], IPD[right][0]), max(IPD[left][0], IPD[right][0]));
                left++;
                right--;
                i += 2;
            }
            else if (fall_events[i][1] == 0)
            { // 左
                printf("%d ", IPD[left++][0]);
                i++;
            }
            else
            {
                printf("%d ", IPD[right--][0]);
                i++;
            };
        };
        printf("\n");
    };
    return 0;
}