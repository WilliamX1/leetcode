#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int N; cin >> N;
    bool A[20][20];  //最大为15 * 15，扩容一行两列消除边界特殊情况；
    int B[20][20];
    for (int j = 0; j <= N + 1; j++) B[0][j] = B[1][j] = B[j][0] = B[j][N + 1] = 0;  //代表输入
    char tmp;
    int min = 1000, sum = 0;
    int pos = 1;
    for (int i = 1; i <= N; i++) pos *= 2;

    for (int j = 0; j <= N + 1; j++) A[0][j] = A[j][0] = A[j][N + 1] = 0;  //边界设置为0，代表白砖
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> tmp;
            if (tmp == 'w') A[i][j] = 0;
            else A[i][j] = 1;
        }

    for (int k = 1; k <= pos; k++)
    {
        for (int i = 2; i <= N + 1; i++)
        {
            for (int j = 1; j <= N; j++)
                B[i][j] = (A[i - 1][j] + B[i - 1][j - 1] + B[i - 1][j + 1] + B[i - 1][j] + B[i - 2][j] + 1) % 2;
        }

        int i;
        for (i = 1; i <= N && B[N + 1][i] == 0; i++);
        if (i > N)
        {
            sum = 0;
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    sum += B[i][j];
            if (sum < min)
            {
                /*for (int i = 1; i <= N; i++)
                {
                    cout << endl;
                    for (int j = 1; j <= N; j++)
                        cout << B[i][j] << " ";
                } */   
                min = sum;
            }
        }

        B[1][1]++;
        for (int i = 1; i < N && B[1][i] == 2; i++)
        {
            B[1][i] = 0;
            B[1][i + 1] += 1;
        }  //产生第一行输入序列
    }
    if (min != 1000)
        cout << min << endl;
    else
        cout << "inf" << endl;
    }
    
    return 0;
}