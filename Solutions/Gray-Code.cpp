class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int start = 0, end = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = end; j >= start; j--)
                ans.push_back((1 << (i - 1)) | ans[j]);
            end = ans.size() - 1;
        };
        return ans;
    }
};