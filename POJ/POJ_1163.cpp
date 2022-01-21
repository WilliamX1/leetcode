#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    int Arr[101][101];
    int Brr[101][101];

    for (int i = 1; i <= N ; i++)
        for (int j = 1; j <= i; j++)
            cin >> Arr[i][j];
    for (int i = 1; i <= N; i++)
        Brr[N][i] = Arr[N][i];
    for (int i = N - 1; i >= 1; i--)
        for(int j = 1; j <= i; j++)
            Brr[i][j] = Arr[i][j] + max(Brr[i + 1][j], Brr[i + 1][j + 1]);
    cout << Brr[1][1];
}
