#include <iostream>

using namespace std;

/*const int X = 3;
const int Y = 30;
int A[X + 2][Y + 2];
int sum = 0;

void Cover(int total, int n, int x, int y)
{
    if (2 * total == 3 * n)
    {
        bool flag = true;
        for (int i = 1; i <= X && flag; i++)
            for (int j = 1; j <= n; j++)
                if (A[i][j] == 0) { flag = false; break;}
        if (flag) sum++;
        sum++;
        return;
    }
    if (A[x][y] == 1)  //该点已经被占用
    {
        if (x == 3) Cover(total , n, 1, y + 1);
        else Cover(total, n , x + 1, y);
    }
    else
    {
        if (x == 3 && A[x][y + 1] == 0)
        {
            A[x][y] = A[x][y + 1] = 1;
            Cover(total + 1, n, 1, y + 1);
            A[x][y] = A[x][y + 1] = 0;
        }
        else
        {
            if (A[x + 1][y] == 0)
            {
                A[x][y] = A[x + 1][y] = 1;
                Cover(total + 1, n, x + 1, y);
                A[x][y] = A[x + 1][y] = 0;
            }
            if (A[x][y + 1] == 0)
            {
                A[x][y] = A[x][y + 1] = 1;
                Cover(total + 1, n, x + 1, y);
                A[x][y] = A[x][y + 1] = 0;
            }
        }
    }
}*/
int main()
{
    const int N = 100;
    int n; cin >> n;
    long long int *A = new long long int[N + 1]; int xb = 0;
    long long int *S = new long long int[N + 1];
    for (int i = 0; i <= N; i++) S[i] = 0;
    S[0] = 1;
    S[2] = 3;
    for (int i = 4; i <= N; i += 2)
        S[i] = 4 * S[i - 2] - S[i - 4];
    S[0] = 0;


    while(n != -1)
    {
        A[++xb] = S[n];
        cin >> n;
    }
    for (int i = 1; i <= xb; i++)
        cout << A[i] << endl;


    /*while(n != -1)
    {
        for (int i = 0; i <= X + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            A[i][j] = 0;
        for (int i = 0; i <= n + 1; i++)
            A[0][i] = A[X + 1][i] = 1;
        for (int i = 0; i <= X + 1; i++)
            A[i][0] = A[i][n + 1] = 1;

        Cover(total, n, 1, 1);
        cout << sum << endl;
        total = sum = 0;
        cin >> n;
    };*/
    return 0;
}
