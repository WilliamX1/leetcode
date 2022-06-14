/*************************************************************
    date: Spring 2022
    copyright: Bintao Yu
    DO NOT distribute this code without my permission.
**************************************************************/
/********* Begin **********/
#include <iostream>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
};

int max(int a, int b)
{
    return a > b ? a : b;
};

int main()
{
    int *p = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> p[i];
        p[i] = min(p[i], 10);
    };

    int ans = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                else if ((p[i] + p[j] + p[k]) % 10 == 0)
                {
                    ans = (p[0] + p[1] + p[2] + p[3] + p[4]) % 10;
                    cout << (ans == 0 ? 10 : ans) << endl;
                    return 0;
                }
                else
                {
                };
            };
    cout << 0 << endl;
    return 0;
}
/********** End **********/
// You can use class.cpp and class.h if you want to.