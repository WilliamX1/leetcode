#include <iostream>

using namespace std;

bool cal(int ch, int &x, int y)
{
    if (ch == 1) { x += y; return true;};
    if (ch == 2) { x -= y; return true;};
    if (ch == 3) { x *= y; return true;};
    if (ch == 4)
        if (y != 0 && (x % y) == 0) {x /= y; return true;}
        else return false;
}

int main()
{
    int t; cin >> t;

    int A[5]; //代表4张牌
    //1加法，2减法，3乘法，4除法

    while(t--)
    {
        scanf("%d%d%d%d", &A[1], &A[2], &A[3], &A[4]);

        int MAX = -100;

        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                if (j == i) continue;
                else
                    for (int k = 1; k <= 4; k++)
                        if (k == j || k == i) continue;
                        else
                            for (int s = 1; s <= 4; s++)
                                if (s == i || s == j || s == k) continue;
                                else
                                    for (int a = 1; a <= 4; a++)
                                        for (int b = 1; b <= 4; b++)
                                            for (int c = 1; c <= 4; c++)
                                            {
                                                while (1)
                                                {
                                                    int res_1 = A[i];
                                                    if (!cal(a, res_1, A[j])) break;
                                                    if (!cal(b, res_1, A[k])) break;
                                                    if (!cal(c, res_1, A[s])) break;
                                                    if (res_1 <= 24 && res_1 > MAX) MAX = res_1;
                                                    break;
                                                    //cout << res << endl;
                                                }
                                                while (1)
                                                {
                                                    int res_1 = A[i];
                                                    if (!cal(a, res_1, A[j])) break;
                                                    int res_2 = A[k];
                                                    if (!cal(c, res_2, A[s])) break;
                                                    if (!cal(b, res_1, res_2)) break;
                                                    if (res_1 <= 24 && res_1 > MAX) MAX = res_1;
                                                    break;
                                                }
                                            }
        printf("%d\n", MAX);
    }

    return 0;
}
