#include <iostream>
#include <cstring>
using namespace std;

char C[110];
int main()
{
    string A, B;  //A明文 B密文 C解密

    cin >> A >> B;

    int len = A.length();
    int boom;
    int C_xb = 0;
    int i, j, k;

    for (i = 2; i <= len; i++)
        if (len % i == 0)
        {
            C_xb = -1;
            boom = len / i;
            for (j = 0; j < i; j++)
                for (k = 0; k < boom; k++)
                    C[++C_xb] = A[j + k * i];
            for (j = 0; j < len && C[j] == B[j]; j++);
            if (j == len) {cout << i; return 0;};
        }
    cout << "No Solution";
    return 0;
}
