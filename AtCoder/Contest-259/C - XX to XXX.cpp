#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int indexS = 0, sizeS = S.size(), indexT = 0, sizeT = T.size();
    while (indexS < sizeS && indexT < sizeT)
    {
        if (S[indexS] != T[indexT])
        {
            cout << "No" << endl;
            return 0;
        }
        else
        {
            int nextIndexS = indexS + 1, nextIndexT = indexT + 1;
            while (nextIndexS < sizeS && S[nextIndexS] == S[indexS])
                nextIndexS++;
            while (nextIndexT < sizeT && T[nextIndexT] == T[indexT])
                nextIndexT++;

            int lenS = nextIndexS - indexS, lenT = nextIndexT - indexT;
            if (lenS == 1 && lenT != 1 || lenS > lenT)
            {
                cout << "No" << endl;
                return 0;
            };

            indexS = nextIndexS;
            indexT = nextIndexT;
        };
    };
    cout << (indexS == sizeS && indexT == sizeT ? "Yes" : "No") << endl;
    return 0;
}