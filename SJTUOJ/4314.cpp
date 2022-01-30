#include <iostream>

using namespace std;

int A[100010];

int main()
{
    int N; cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    bool flag;
    int sum = 0, tmp;

    do
    {
        flag = false;
        for (int i = 0; i < N - 1; i++)
            if (A[i + 1] < A[i])
            {
                tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                sum++;
                flag = true;
            }
    }while(flag);
    cout << sum;
    return 0;
}
