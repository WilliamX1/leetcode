#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K; cin >> N >> K;
        string str; cin >> str; str = ' ' + str;
        int tot = 0;
        for (int i = 1; i <= N / 2; i++) {
            if (str[i] != str[N - i + 1])
                tot++;
        };
        cout << "Case #" << t << ": " << abs(tot - K) << endl;
    };
    return 0;
};