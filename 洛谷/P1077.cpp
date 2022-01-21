#include <bits/stdc++.h>

using namespace std;

int A[110][110];
int B[110];
const int Mod = 1000007;

int main()
{
    int n, k; cin >> n >> k;

    memset(B, 0, sizeof(B));
    for (int i = 1; i <= n; i++)
        cin >> B[i];

    memset(A, 0, sizeof(A));
    A[0][0] = 1;
    for (int i = 1; i <= n; i++)  //A[i][j]�����ֹ��i�ֻ���j�̵İڷ���
        for (int j = 0; j <= k; j++)
        {
            if (j == 0) A[i][j] = 1;  //��Ϊ0���⴦��
            else
                for (int s = 0; s <= j && s <= B[i]; s++)  //s��������
                {
                    A[i][j] += A[i - 1][j - s];
                    A[i][j] %= Mod;
                }
        }
    cout << A[n][k];
    return 0;
}
