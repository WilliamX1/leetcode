#include <iostream>

using namespace std;

int A[1010];
int main()
{
    char tmp;
    int N; cin >> N;
    int M = 0, M_xb;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp >> A[i];
        if (A[i] >= M) {M = A[i]; M_xb = i;};
        //找到最右边的最大值下标
    }cin >> tmp;

    int i;
    int sum = 0, tmp_sum = 0;

    for (i = 2; i <= M_xb && A[i - 1] <= A[i]; i++);
    int Lmax = A[i - 1];

    for (; i <= M_xb; i++)
    {
        if (A[i] >= Lmax)
        {
            Lmax = A[i];
            sum += tmp_sum;
            tmp_sum = 0;
        }
        else tmp_sum += Lmax - A[i];
    }

    for (i = N - 1; i >= M_xb && A[i] >= A[i + 1]; i--);
    int Rmax = A[i + 1];
    tmp_sum = 0;
    for (; i >= M_xb; i--)
    {
        if (A[i] >= Rmax)
        {
            Rmax = A[i];
            sum += tmp_sum;
            tmp_sum = 0;
        }
        else tmp_sum += Rmax - A[i];
    }

    cout << sum;
    return 0;
}
