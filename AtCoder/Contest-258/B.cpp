#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    const vector<vector<int>> positions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int64_t ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            for (const vector<int> &pos : positions)
            {
                vector<char> tmps;
                int x = i, y = j;
                while (tmps.size() < N)
                {
                    tmps.push_back(nums[x][y]);
                    x = (x + pos[0] + N) % N;
                    y = (y + pos[1] + N) % N;
                };
                int64_t num = 0;
                for (const char &tmp : tmps)
                    num = num * 10L + (int64_t)(tmp - '0');
                ans = max(ans, num);
            };
        };
    cout << ans << endl;
    return 0;
}