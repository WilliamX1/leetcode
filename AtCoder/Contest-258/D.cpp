#include <iostream>

using namespace std;

int main()
{
    int64_t N, X;
    cin >> N >> X;
    int64_t A, B, ans = INT64_MAX, tt = 0;

    for (int64_t i = 0; i < min(N, X); i++)
    {
        cin >> A >> B;
        tt += A + B;
        ans = min(ans, (X - i - 1) * B + tt);
    };
    cout << ans << endl;
    return 0;
}