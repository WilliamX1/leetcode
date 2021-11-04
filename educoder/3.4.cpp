#include<bits/stdc++.h>
using namespace std;
const int MXN = 100005;
int le[MXN], ri[MXN];

int main(void){
    int n;
    cin >> n;

    vector<bool> flag(n, false);
    for(int i = 0; i < n; i++){
        cin >> le[i] >> ri[i];
        flag[le[i]] = flag[ri[i]] = true;
    };

    int head = 0;
    for (int i = 1; i < n; i++)
        if (flag[i] == false) {
            head = i;
            break;
        };

    deque<int> res;
    deque<int> tmp;
    if (head != 0) tmp.push_back(head);

    while (!tmp.empty()) {
        int front = tmp.front(); tmp.pop_front(); res.push_back(front);
        if (front == 0) continue;
        else {
            tmp.push_back(le[front]);
            tmp.push_back(ri[front]);
        };
    };

    while (!res.empty() && res.front() != 0) {
        res.pop_front();
    };

    while (!res.empty() && res.front() == 0) {
        res.pop_front();
    };

    std::cout << (res.empty() ? 'Y' : 'N') << std::endl;
    //
    //
    return 0;
}
