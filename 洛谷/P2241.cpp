#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m; //n �� m����
    int MIN = min(n, m);

    long long int Z = 0; //������
    for (int i = 1; i <= MIN; i++)  //�����α߳�
        Z += (long long)(m - i + 1) * (long long)(n - i + 1);

    long long int C = 0; //�����Σ��������Σ�
    for (int i = 1; i <= n; i++)  //����
        for (int j = 1; j <= m; j++)  //���
            C += (long long)(n - i + 1) * (long long)(m - j + 1);
    cout << Z << " " << C - Z;
    return 0;
}
