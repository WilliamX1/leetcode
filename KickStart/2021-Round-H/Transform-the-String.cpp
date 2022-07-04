#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string S, F;
    for (int i = 1; i <= T; i++)
    {
        cin >> S >> F;
        int ans = 0;
        for (const char &ch : S)
        {
            int tot = 0x7fffffff;
            for (const char &tar_ch : F)
            {
                if (tar_ch >= ch)
                    tot = min(tot, min(tar_ch - ch, ch - 'a' + 'z' - tar_ch + 1));
                else
                    tot = min(tot, min(ch - tar_ch, tar_ch - 'a' + 'z' - ch + 1));
            };
            ans += tot;
        };
        printf("Case #%d: %d\n", i, ans);
    };
    return 0;
}