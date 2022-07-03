#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string str;
    vector<bitset<3000 + 1>> bbmatrix(N);
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            bbmatrix[i][j] = str[j] - '0';
    };

    int64_t ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (bbmatrix[i][j])
            {
                // cout << i << ' ' << j << ' ' << (bbmatrix[i] & bbmatrix[j]).count() << endl;
                ans += (int64_t)(bbmatrix[i] & bbmatrix[j]).count();
            };
        };
    ans /= 6;
    cout << ans << endl;
    return 0;
}