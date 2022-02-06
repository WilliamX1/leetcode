class Solution {
public:
    long long smallestNumber(long long num) {
        if (num >= 0) {
            vector<int> v;
            while (num > 0) {
                v.push_back(num % 10);
                num /= 10;
            };
            sort(v.begin(), v.end(), less<int>());
            long long ans = 0;
            int idx = 0;
            while (idx < v.size() && v[idx] == 0) idx++;
            if (idx < v.size()) ans = v[idx];
            for (int i = idx - 1; i >= 0; i--) {
                ans = ans * 10 + v[i];
            };
            for (int i = idx + 1; i < v.size(); i++) {
                ans = ans * 10 + v[i];
            };
            return ans;
        } else {
            vector<int> v;
            num = -num;
            while (num > 0) {
                v.push_back(num % 10);
                num /= 10;
            };
            sort(v.begin(), v.end(), greater<int>());
            long long ans = v[0];
            for (int i = 1; i < v.size(); i++) {
                ans = ans * 10 + v[i];
            };
            return -ans;
        }
    }
};