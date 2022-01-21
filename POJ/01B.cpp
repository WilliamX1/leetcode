#include <iostream>

using namespace std;

bool is(int x, int y)
{
    int m;
    while(y)
    {
        m = x % y;
        x = y;
        y = m;
    }
    return x == 1;
}

int main()
{
    int N, A, B; cin >> N >> A >> B;
    double top = double(A) / B;

    double MAX = 0.0, tmp;
    int t, b;
    for (int i = N; i > 1; i--)
    {
        for (int j = i - 1; j > 0; j--)
            if (is(i, j) && double(j) / i < top)
            {
                tmp = double(j) / i;
                if (tmp > MAX)
                {
                    MAX = tmp;
                    t = j;
                    b = i;
                }
                break;
            }
    }

    cout << t << " " << b;

    return 0;
}
