#include <iostream>

using namespace std;
const int N = 1200;
long long int A[N + 1][N + 1];
int main()
{
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            A[i][j] = 0;
    for (int i = 0; i <= N; i++) A[i][i] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int x = i - 2 * j;

            if (x == 0) A[i][j]++;
            else
                for (int k = j; k <= x; k++)
                    A[i][j] += A[x][k];
        }
        for (int j = 1; j <= i; j++)
            A[i][0] += A[i][j];
    }

    int ch; cin >> ch;
    while(ch != 0)
    {
        cout << ch << " " << A[ch][0] << endl;
        cin >> ch;
    }
    return 0;
}
