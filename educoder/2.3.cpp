#include<bits/stdc++.h>
using namespace std;


int find(int n, int m) {
    if (n == 1) return 0;
    return (find(n - 1, m) + m) % n;
}

int main(){
    int n,m;
    cin>>n>>m;

    //your code 
    cout << find(n, m) + 1 << endl;
    //
}