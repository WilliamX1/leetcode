class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();
        int cur = citations.front(), ans = 0;
        for (int i = 0; i < len; i++)
            ans = max(ans, min(citations[i], len - i));
        return ans;
    }
};