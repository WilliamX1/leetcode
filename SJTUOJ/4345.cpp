#include <bits/stdc++.h>

using namespace std;
inline __int128 read(){
    __int128 x = 0;
    char ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
inline void print(__int128 x){
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    __int128 cifang[30];
    cifang[0] = 1;
    for (int i = 1; i < 30; i++) cifang[i] = cifang[i - 1] * 10;

    __int128 tmp;
    while(tmp = read()){

        __int128 A[100];
        __int128 B[1000];  //循环节长度不超过1000吧
        int B_index = -1;
        B[++B_index] = tmp;

        bool flag = true;
        int i, j;
        while(flag){
            for (i = 0; i < B_index; i++)
                if (B[B_index] == B[i]){
                    flag = false;
                    break;
                }
            if (!flag){
                for (j = i; j < B_index; j++)
                    print(B[j]), printf(" ");
                printf("\n");
                break;
            }

            int index = -1;
            while(tmp > 0)
            {
                A[++index] = (tmp % 10);
                tmp /= 10;
            }
            int len = index + 1;
            __int128 M = 0, m = 0;

            sort(A, A + len, less<int>());
            for (int i = 0; i < len; i++)
                M += cifang[i] * A[i];
            for (int i = 0; i < len; i++)
                m += cifang[len - i - 1] * A[i];
            tmp = B[++B_index] = M - m;
        }
    }
    return 0;
}
