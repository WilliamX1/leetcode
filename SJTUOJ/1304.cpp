#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    int M = 0, m = 0x3fffffff;
    int N, L, x; scanf("%d%d", &N, &L);

    for (int i = 1; i <= N; i++){
        scanf("%d", &x);
        if (i & 1){
            if (L - x > M) M = L - x;
            if (L - x < m) m = L - x;
        }
        else{
            if (x > M) M = x;
            if (x < m) m = x;
        }
    }
    cout << m << " " << M;
    return 0;
}
