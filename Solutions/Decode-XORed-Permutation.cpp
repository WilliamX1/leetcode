#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector<int> perm(n, 0);
        int total = 0;
        for (int i = 1; i <= n; i++) total ^= i;
        int tmp = 0;
        for (int i = 1; i < n - 1; i += 2) tmp ^= encoded[i];
        perm[0] = total ^ tmp;

        for (int i = 1; i < n; i++)
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        return perm;
    }
};

int main()
{
    Solution S;
    vector<int> v = {6,5,4,6};
    S.decode(v);
    return 0;
}