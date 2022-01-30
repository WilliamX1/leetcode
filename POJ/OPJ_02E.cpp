#include <iostream>
#include <cmath>
using namespace std;

double A[10];
double l, r, m;
int N;

bool is(double x)
{
    double fx = 0;
    for (int i = 0; i <= N; i++)
        fx += A[i] * pow(x, i);

    double t = 0;
    for (int i = 0; i <= N; i++)
        t += A[i] * pow(l, i);

    return fx * t > 0;
}

int main()
{
    A[0] = -121;
    A[1] = 274;
    A[2] = -225;
    A[3] = 85;
    A[4] = -15;
    A[5] = 1;

    l = 1.5, r = 2.4, N = 5;

    while(r - l > 1e-7)
    {
        m = (l + r) / 2;
        if (is(m)) l = m;
        else r = m;
    }
    printf("%.6f", m);
    return 0;
}
