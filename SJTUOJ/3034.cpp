#include <bits/stdc++.h>
#include <cstring>

using namespace std;
const int N = 101000;
bool flag[N + 1];
int prime[N + 1];
int num = 0;

void getPrime(){
    memset(flag, 0, sizeof(flag));

    flag[2] = true;
    prime[++num] = 2;

    for (int i = 3; i <= N; i++){
        if (!flag[i])
            prime[++num] = i;
        for (int j = 1; j <= num && i * prime[j] <= N; j++)
        {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    getPrime();
    int k; cin >> k;

    int left = 1, right = num, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if (k == prime[mid]){
            left = right = mid;
            break;
        }
        else if (k < prime[mid])
            right = mid - 1;
        else left = mid + 1;
    }
    cout << prime[left] - prime[right];
    return 0;
}
