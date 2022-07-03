#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int64_t distance(int64_t x1, int64_t y1, int64_t x2, int64_t y2, int64_t B, int64_t K)
{
    int64_t ans = INT64_MAX;
    if (x1 % B == 0 && y2 % B == 0 || x2 % B == 0 && y1 % B == 0)
        ans = min(ans, abs(y2 - y1) + abs(x2 - x1));
    if (x1 % B == 0 && x2 % B == 0)
    {
        ans = min(ans, abs(x2 - x1) * K + abs(y2 - y1));
        ans = min(ans, abs(y1 - y1 / B * B) + abs(x2 - x1) + abs(y2 - y1 / B * B));
        ans = min(ans, abs(y1 - (y1 / B * B + B)) + abs(x2 - x1) + abs(y2 - (y1 / B * B + B)));
    }
    if (y1 % B == 0 && y2 % B == 0)
    {
        ans = min(ans, abs(y2 - y1) * K + abs(x2 - x1));
        ans = min(ans, abs(x1 - x1 / B * B) + abs(y2 - y1) + abs(x2 - x1 / B * B));
        ans = min(ans, abs(x1 - (x1 / B * B + B)) + abs(y2 - y1) + abs(x2 - (x1 / B * B + B)));
    };
    return ans;
};

int main()
{
    int64_t T;
    cin >> T;
    int64_t B, K, Sx, Sy, Gx, Gy;
    for (int64_t i = 0; i < T; i++)
    {
        cin >> B >> K >> Sx >> Sy >> Gx >> Gy;

        vector<vector<int64_t>> start, end;
        int64_t baseStartX = Sx / B * B, baseStartY = Sy / B * B;
        start.push_back({baseStartX, Sy, (Sy % B ? K : 1) * (Sx - baseStartX)});
        start.push_back({baseStartX + B, Sy, (Sy % B ? K : 1) * (baseStartX + B - Sx)});
        start.push_back({Sx, baseStartY, (Sx % B ? K : 1) * (Sy - baseStartY)});
        start.push_back({Sx, baseStartY + B, (Sx % B ? K : 1) * (baseStartY + B - Sy)});

        int64_t baseEndX = Gx / B * B, baseEndY = Gy / B * B;
        end.push_back({baseEndX, Gy, (Gy % B ? K : 1) * (Gx - baseEndX)});
        end.push_back({baseEndX + B, Gy, (Gy % B ? K : 1) * (baseEndX + B - Gx)});
        end.push_back({Gx, baseEndY, (Gx % B ? K : 1) * (Gy - baseEndY)});
        end.push_back({Gx, baseEndY + B, (Gx % B ? K : 1) * (baseEndY + B - Gy)});

        int64_t ans = INT64_MAX;
        int64_t disX = abs(Sx - Gx), disY = abs(Sy - Gy);
        if (Sx % B == 0 || Gx % B == 0)
            ans = min(ans, disX * K + disY);
        if (Gx % B == 0 || Gy % B == 0)
            ans = min(ans, disY * K + disX);
        ans = min(ans, (disX + disY) * K);

        for (const vector<int64_t> &s : start)
            for (const vector<int64_t> &e : end)
            {
                int64_t tot = distance(s[0], s[1], e[0], e[1], B, K) + s[2] + e[2];
                ans = min(ans, tot);

                // cout << s[0] << ' ' << s[1] << ' ' << s[2] << ' ' << e[0] << ' ' << e[1] << ' ' << e[2] << ' ' << tot
                //      << ' ' << ans << endl;
            };

        cout << ans << endl;
    };
    return 0;
};