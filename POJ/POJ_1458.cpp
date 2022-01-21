#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char A[1000], B[1000];



    while(cin >> A >> B)
    {
        int lenA, lenB;
        lenA = strlen(A); lenB = strlen(B);

        int **V = new int*[lenA + 1];
        for (int i = 0; i <= lenA; i++)
            V[i] = new int[lenB + 1];
        for (int i = 0; i <= lenA; i++)
            V[i][0] = 0;
        for (int i = 0; i <= lenB; i++)
            V[0][i] = 0;

        for (int i = 1; i <= lenA; i++)
            for (int j = 1; j <= lenB; j++)
                if (A[i - 1] == B[j - 1])
                    V[i][j] = V[i - 1][j - 1] + 1;
                else
                    V[i][j] = max(V[i - 1][j], V[i][j - 1]);
        cout << V[lenA][lenB] << endl;
    }

    return 0;
}
