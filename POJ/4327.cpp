#include <iostream>
#include <algorithm>
#include <cstring>
//��������е�a,b���ٽ���ͬ��a,b���кϲ����ٽ���̰���㷨�������䣻��ÿ���㿴��������һ���㣻
using namespace std;

int n, m;
int MIN;

struct data
{
    double x;
    double y;
    int label;
};
data D[20];

struct ABxy
{
    double a;
    double b;
    int n1;  //����A�еڼ������γɵ�
    int n2;
};
ABxy B[2000];  //���a��b����
int b_xb;

int a, b;
void cal(double x1, double x2, double y1, double y2)
{
    a = (x2 * y1 - x1 * y2) / (x1 * x2 * (x1 - x2));
    b = (x2 * x2 * y1 - x1 * x1 * y2) / (x1 * x2 * (x2 - x1)) ;
}
bool myCompare(ABxy A, ABxy B)
{
    if (A.a == B.a) return A.b < B.b;
    return A.a < B.a;
}

int FINAL[2000][20]; int f_xb;

int FF[20];

void Dfs(int x, int y, int total)
{
    if (total == n) { MIN = min(MIN, total); return;}

    for (int i = 1; i <= n; i++)
        if (FINAL[x][i]) FF[FINAL[x][i]] = -1;
    for (int i = x; i <= f_xb; i++)

    for (int i = 1; i <= n; i++)
        if (FINAL[x][i] == -1) FF[FINAL[x][i]] = 0;
    return;
}

int main()
{
    int T; cin >> T;


    cin >> n >> m;
    b_xb = 0; f_xb = 1; MIN = 1e9;
    memset(FINAL, 0, sizeof(FINAL));
    memset(FF, 0, sizeof(FF));

    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> D[j].x >> D[j].y;
            D[j].label = j;
        }

        for (int j = 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                ++b_xb;
                cal(D[j].x, D[k].x, D[j].y, D[k].y);
                B[b_xb].a = a; B[b_xb].b = b;
                B[b_xb].n1 = j; B[b_xb].n2 = k;
            }

        sort(B + 1, B + b_xb + 1, myCompare);

        FINAL[1][B[1].n1] = FINAL[1][B[1].n2] = 1;
        for (int j = 2; j <= b_xb; j++)
        {
            if (B[j].a != B[j - 1].a || B[j].b != B[j - 1].b) ++f_xb;

            FINAL[f_xb][B[j].n1] = FINAL[f_xb][B[j].n2] = 1;
        } //FINAL[i][j]�����i����a,b��ֵ�Ƿ��ܹ����ǵ���j����


    }
}
