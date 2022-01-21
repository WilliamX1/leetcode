#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N; cin >> N;
    int tmp_N = N;
    int M1 = pow(double(N), 0.3333) + 1;
    int M2, M3;
    int MIN = 10000000;

    for (int i = M1; i >= 1; i--)
        if (N % i == 0)
        {
            M1 = i;
            tmp_N = N / M1;
            M2 = sqrt(tmp_N);
            for (int j = M2; j >= 1; j--)
                if (tmp_N % j == 0)
                {
                    M2 = j;
                    M3 = tmp_N / j;
                    MIN = min(MIN, 2 * (M1 * M2 + M1 * M3 + M2 * M3));
                    //cout << M1 << " " << M2 << " " << M3 << " " << MIN << endl;
                }
        }
    cout << MIN;
    return 0;
}
