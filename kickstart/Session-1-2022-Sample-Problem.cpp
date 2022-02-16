#include <iostream>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, M; cin >> N >> M;
        int tot = 0, tmp;
        while (N-- > 0) {
            cin >> tmp;
            tot += tmp;
        };
        cout << "Case #" << i << ": " << tot % M << endl;
    };
    return 0;
}