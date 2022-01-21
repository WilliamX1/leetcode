#include <iostream>
#include <cstring>
using namespace std;

int A[10][10];
int B[10];

int main()
{
    int n; cin >> n;

    while(n-- > 0)
    {

    bool flag = true;

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            scanf("%d", &A[i][j]);

    //验证行
    for (int i = 1; i <= 9 && flag; i++)
    {
        memset(B, 0, sizeof(B));
        for (int j = 1; j <= 9; j++)
            if (B[A[i][j]] == 1)
            {
                flag = false;
                break;
            }
            else B[A[i][j]] = 1;
    }

    //验证行
    for (int j = 1; j <= 9 && flag; j++)
    {
        memset(B, 0, sizeof(B));
        for (int i = 1; i <= 9; i++)
            if (B[A[i][j]] == 1)
            {
                flag = false;
                break;
            }
            else B[A[i][j]] = 1;
    }

    //验证块
    for (int i = 1; i <= 9 && flag; i += 3)
    {
        for (int j = 1; j <= 9 && flag; j += 3)
        {
            memset(B, 0, sizeof(B));
            for (int k = 0; k < 3; k++)
                for (int s = 0; s < 3; s++)
                    if (B[A[i + k][j + s]] == 1)
                    {
                        flag = false;
                        break;
                    }
                    else B[A[i + k][j + s]] = 1;

        }
    }

    if (flag) cout << "Right" << endl;
    else cout << "Wrong" << endl;

    }
    return 0;
}
