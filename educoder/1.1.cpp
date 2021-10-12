#include<cstdio>
#include<iostream>
using namespace std;

int a[10000];
int main(void){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    /////////////////////////
    // n,m,a已经输入
    
    int ans = 0x7fffffff, tot = 0;
    for (int i = 0; i < m; i++) tot += a[i];
    ans = tot < ans ? tot : ans;
    for (int i = m; i < n; i++) {
        tot += a[i] - a[i - m];
        ans = tot < ans ? tot : ans;
    };
    std::cout << ans << std::endl;

    // 在标准输出流中输出(cout,printf)
    /////////////////
    return 0;
}
