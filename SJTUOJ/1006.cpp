#include <iostream>
#include <cstring>
using namespace std;
int A[4010000];

int main()
{

    int n;

    while(scanf("%d",&n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            cin >> A[i];
        if (n == 1 || n == 0 || n == 2) cout << "Game Over";

        else
        {
            int MAX = A[1];

            for (int i = 2; i <= n; i++)
                if (A[i - 1] > 0)
                {
                    A[i] += A[i - 1];
                    if (A[i] > MAX) MAX = A[i];
                }
            if (MAX <= 0) cout << "Game Over";
            else cout << MAX << endl;
        }
    }

    return 0;
}
