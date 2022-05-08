/*************************************************************
    date: Spring 2022
    copyright: Bintao Yu
    DO NOT distribute this code without my permission.
**************************************************************/
/********* Begin **********/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n; cin >> n;
    int* p = new int[n];
    int* flags = new int[10 + 1];
    memset(flags, 0, sizeof(flags));
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        flags[p[i]]++;
    };

    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                if ((i + j + k) % 10 != 0) continue;
                if (flags[i]) {
                    flags[i]--;
                    if (flags[j]) {
                        flags[j]--;
                        if (flags[k]) {
                            flags[k]--;
                            ans++;

                            k--;
                            continue;
                        };
                        flags[j]++;
                    };
                    flags[i]++;
                };
            };
        };
    };
    cout << ans << endl;
    return 0;
}

/********** End **********/
// You can use class.cpp and class.h if you want to.