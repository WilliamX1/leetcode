#include <bits/stdc++.h>

using namespace std;

int main()
{
    double r, a;
    double square, res = 0;
    double angel;
    while(cin >> r >> a){
        angel = acos(a / r);
        square = r * r * angel - 0.5 * r * r * sin(2 * angel);
        res = max(res, square);
    }
    printf("%.2f", res);
    return 0;
}
