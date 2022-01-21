#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int E, EM, M, MH, H;
    cin >> E >> EM >> M >> MH >> H;

    long long int tmpE = E + EM;
    long long int tmpM = M + EM;
    long long int tmpH = H + MH;


    long long int F = min(tmpE, tmpM);
    F = min(F, tmpH);

    long long int tmpEM;
    long long int tmpMH;

    long long int l = 0, r = 2 * F, m;

    bool flag;

    while(l <= r)
    {
        //各种题目还差多少满足要求

        m = (l + r) / 2;

        flag = false;

        tmpE = m - E;
        tmpM = m - M;
        tmpH = m - H;

        tmpEM = EM; if (tmpE > 0) tmpEM -= tmpE;
        tmpMH = MH; if (tmpH > 0) tmpMH -= tmpH;

        if (tmpEM >= 0 && tmpMH >= 0 && tmpEM + tmpMH >= tmpM) flag = true;

        if (flag) l = m + 1;
        else r = m - 1;
    }

    cout << r;

    return 0;
}
