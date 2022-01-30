#include <iostream>

using namespace std;

int main()
{
    int x1, x2;

    int A_1 = 2, A_2 = 0;  //香蕉
    int B_1 = 250, B_2 = 200; //面粉
    int C_1 = 75, C_2 = 150; //糖
    int D_1 = 100, D_2 = 150; //黄油
    int E_1 = 0, E_2 = 75; //可可粉

    int M_1 = 400, M_2 = 450;  //单价

    int T_1 = 100, T_2 = 100; //数量上限

    int A, B, C, D, E;
    scanf("%d%d%d%d%d", &B, &A, &C, &D, &E);

    T_1 = min(T_1, A / A_1); T_1 = min(T_1, B / B_1);
    T_1 = min(T_1, C / C_1); T_1 = min(T_1, D / D_1);
    T_2 = min(T_2, B / B_2); T_2 = min(T_2, C / C_2); T_2 = min(T_2, D / D_2); T_2 = min(T_2, E / E_2);

    int MAX = 0, i_max = 0, j_max = 0;

    for (int i = 0; i <= T_1; i++)
    {
        for (int j = T_2; j >= 0; j--)
        {
            if (A_1 * i + A_2 * j <= A && B_1 * i + B_2 * j <= B &&
                C_1 * i + C_2 * j <= C && D_1 * i + D_2 * j <= D &&
                E_1 * i + E_2 * j <= E)
            {
                if (i * M_1 + j * M_2 > MAX)
                {
                    MAX = i * M_1 + j * M_2;
                    i_max = i, j_max = j;
                }
                break;
            }
        }
    }

    printf("%d\n%d\n%d", MAX, i_max, j_max);

    return 0;
}
