#include<bits/stdc++.h>
using namespace std;

int order[50000];
int main(void){
    int t;
    cin >>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>order[i];

        // solve
        stack<int> s1, s2;
        int idx = 0, flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (order[idx] == i) {
                idx++;
            } else if (!s1.empty() && order[idx] == s1.top()) {
                idx++;
                s1.pop();
            } else if (s1.size() < m) s1.push(i);
            else {
                flag = 0;
                break;
            };
            while (!s1.empty() && order[idx] == s1.top()) {
                idx++;
                s1.pop();
            };
        };
        cout << (flag && idx == n ? "YES\n" : "NO\n");
        //
    }
    return 0;
}
