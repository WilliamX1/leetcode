class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0, n = reward1.size();
        vector<int> minus1, minus2;
        for (int i = 0; i < n; i++) {
            if (reward1[i] > reward2[i]) {
                ans += reward1[i];
                k--;

                minus1.push_back(reward1[i] - reward2[i]);
            } else {
                ans += reward2[i];
                minus2.push_back(reward2[i] - reward1[i]);
            };
        };


        sort(minus1.begin(), minus1.end());
        sort(minus2.begin(), minus2.end());

        if (k > 0) {
            for (int i = 0; i < k; i++)
                ans -= minus2[i];
        } else {
            for (int i = 0; i < -k; i++)
                ans -= minus1[i];
        };
        
        return ans;
    }
};