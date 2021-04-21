#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        const int len = n;
        bool arr[len + 1];
        memset(arr, 0, sizeof(arr));

        int prev = 1;
        int loop = n;
        /* 模拟 */
        while (--loop > 0) {
            int idx = k;
            int who_leave = prev;
            while (--k > 0) {
                who_leave++;
                if (who_leave > n) who_leave = 1;
                while (arr[who_leave]) {
                    who_leave++; 
                    if (who_leave > n) who_leave = 1;
                };
            };
            arr[who_leave] = true;
            k = idx;

            int next = who_leave + 1;
            if (next > n) next = 1;
            while (arr[next]) {
                next++;
                if (next > n) next = 1;
            };
            k = idx;

            prev = next;
        };

        int res = 1;
        while (arr[res]) res++;
        return res;
    }
};

int main()
{
    Solution S;
    S.findTheWinner(5, 3);
    return 0;
}