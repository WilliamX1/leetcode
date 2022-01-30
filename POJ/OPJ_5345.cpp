#include <iostream>

using namespace std;

int A[100010];

int main()
{
    int N, M; scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    char ch;
    int x;
    for (int i = 1; i <= M; i++)
    {
        cin >> ch >> x;
        if (ch == 'C')
        {
            int j = N;
            while(j--)
            {
                A[j] += x;
                if (A[j] > 65535) A[j] %= 65535;
            }
        }
        else
        {
            int sum = 0;
            int j = N;
            while(j--)
                if ((A[j] >> x) & 1) sum++;
            printf("%d\n", sum);
        }
    }
    return 0;
}
