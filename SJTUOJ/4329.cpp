#include <iostream>
#include <cstring>
using namespace std;
int A[30]; int A_xb;  //代表26个字母出现的次数

char s[100010]; int s_xb;
char t[100010]; int t_xb;
char u[100010]; int u_xb;

int main()
{
    memset(A, 0, sizeof(A));

    //输入
    string a; cin >> a;
    int len = a.length();
    for (int i = 0; i < len; i++)
    {
        ++A[a[i] - 'a' + 1];
        s[i] = a[i];
    }
    //初始化A_xb值
    for (int i = 1; i <= 26; i++)
        if (A[i] == 0) continue;
        else {A_xb = i; break;};

    s_xb = -1;
    t_xb = -1;
    u_xb = -1;

    while(s_xb < len - 1)
    {
        //将新的元素从s队尾转移到t队尾
        t[++t_xb] = s[++s_xb];
        //更新A[A_xb]值
        int tmp_xb = s[s_xb] - 'a' + 1;
        A[tmp_xb]--;
        if (A[A_xb] == 0)  //更新A_xb值
            for (int i = A_xb + 1; i <= 26; i++)
                if (A[i] == 0) continue;
                else {A_xb = i; break;};


        while(t_xb >= 0 && (t[t_xb] - 'a' + 1) <= A_xb)  //检查t中元素是否需要立刻转移到u
        {
            u[++u_xb] = t[t_xb];
            t_xb--;
        }
    }

    for (int i = 0; i <= u_xb; i++)
        cout << u[i];
    for (int i = t_xb; i >= 0; i--)
        cout << t[i];
    return 0;
}
