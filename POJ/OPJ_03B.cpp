#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct node
{
    int a;
    int b;
    int c;
    int d;
};

node A[1000];

bool myCompare(node A, node B)
{
    if (A.a == B.a)
        if (A.b == B.b)
            if (A.c == B.c)
                return A.d < B.d;
            else
                return A.c < B.c;
        else
            return A.b < B.b;
    else
        return A.a < B.a;
}

int main()
{
    int N; cin >> N;

    int A_xb = 0;

    for (int i = 2; i <= N; i++)
        for (int j = i; j <= N; j++)
            for (int k = j; k <= N; k++)
            {
                int res = i * i * i + j * j * j + k * k * k;

                int s;
                for (s = 2; s <= N && s * s * s < res; s++);
                if (s <= N && s * s * s == res)
                {
                    ++A_xb;
                    A[A_xb].a = s;
                    A[A_xb].b = i;
                    A[A_xb].c = j;
                    A[A_xb].d = k;
                }
            }

    sort(A + 1, A + A_xb + 1, myCompare);
    for (int i = 1; i <= A_xb; i++)
        cout << "Cube = " << A[i].a << ", Triple = (" << A[i].b
            << "," << A[i].c << "," << A[i].d << ")\n";
    return 0;
}
