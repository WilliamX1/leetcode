#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string ans = to_string(num);

        vector<int> odd, even;
        while (num > 0) {
            int s = num % 10;
            num /= 10;

            if (s & 1) odd.push_back(s);
            else even.push_back(s);
        };

        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());

        int idx_odd = 0, idx_even = 0;

        for (int i = 0; i < ans.size(); i++) {
            if ((ans[i] - '0') & 1) ans[i] = odd[idx_odd++] + '0';
            else ans[i] = even[idx_even++] + '0';
        };

        return stoi(ans);
    }
};