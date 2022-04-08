class Solution {
public:
    const int N = 26;
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> interval(N, vector<int>(2, -1));
        int n = s.size();
        for (int i = 0; i < n; i++) 
            if (interval[s[i] - 'a'][0] < 0) interval[s[i] - 'a'][0] = i;
        for (int i = n - 1; i >= 0; i--)
            if (interval[s[i] - 'a'][1] < 0) interval[s[i] - 'a'][1] = i;
        
        for (int i = 0; i < N; i++) {
            int left = interval[i][0], right = interval[i][1];
            if (left != -1) {
                while (true) {
                    for (int j = left + 1; j < right; j++) {
                        interval[i][0] = min(interval[i][0], interval[s[j] - 'a'][0]);
                        interval[i][1] = max(interval[i][1], interval[s[j] - 'a'][1]);
                    };
                    if (interval[i][0] != left || interval[i][1] != right) {
                        left = interval[i][0];
                        right = interval[i][1];
                    } else break;
                };
            }
        }
        
                
        sort(interval.begin(), interval.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<string> ans;
        int left = -1;
        for (const vector<int>& ivl : interval) {
            if (ivl[0] > left) { 
                ans.push_back(s.substr(ivl[0], ivl[1] - ivl[0] + 1));
                left = ivl[1];
            };
        };
        return ans;
    }
};