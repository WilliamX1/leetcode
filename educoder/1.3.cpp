#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }
    //输入已经给出 
    int left, right, mid;
    for (int i = 0; i < m; i++) {
        left = 0, right = n - 1;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (a[mid] == b[i]) {
                std::cout << 1 << std::endl;
                break;
            } else if (a[mid] < b[i]) left = mid + 1;
            else right = mid - 1;
        };
        if (left > right) std::cout << 0 << std::endl;
    }
    //在标准输出流中输出(cout,printf)
    return 0;
}