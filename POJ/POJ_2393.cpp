#include <iostream>

using namespace std;

int N, S;

struct week
{
    int C;  //单位价钱
    int Y;  //需要交付
};
week A[10010];

int main()
{
    long long int money = 0;
    int i, j;

    scanf("%d%d", &N, &S);

    for (i = 1; i <= N; i++)
        scanf("%d%d", &A[i].C, &A[i].Y);

    for (i = 1; i <= N; i++)
    {
        money += A[i].C * A[i].Y;
        for (j = i + 1; j <= N; j++)
        {
            if (A[i].C + (j - i) * S <= A[j].C)
                money += (A[i].C + (j - i) * S) * A[j].Y;
            else break;
        }
        i = j - 1;
    }
    cout << money;
    return 0;
}
