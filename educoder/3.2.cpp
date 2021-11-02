#include <bits/stdc++.h>
using namespace std;


int a[100005];

int main(void){
    int n;
    cin>>n;

    priority_queue<int, vector<int>, greater<int> > p;
    for(int i=0;i<n;i++){
        cin>>a[i];
        p.push(a[i]);
    }
    //
    int ans = 0;
    if (p.size() == 1) ans = p.top();
    while (p.size() > 1) {
        int val1 = p.top(); p.pop();
        int val2 = p.top(); p.pop();
        ans += val1 + val2;
        p.push(val1 + val2);
    };
    std::cout << ans;

    return 0;
}
