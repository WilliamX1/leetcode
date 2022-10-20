class Solution
{
  public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> count(n, vector<int>(32, 0)), prefix(n, vector<int>(32, 0));
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            for (int j = 0; j < 32; j++)
            {
                count[i][j] = (num >> j) & 1;
                prefix[i][j] = (i > 0 ? prefix[i - 1][j] : 0) + count[i][j];
            }
        };

        int right = 0;
        vector<int> ans(n);
        vector<int> cc(32, 0);
        for (int left = 0; left < n; left++)
        {
            if (left > 0)
                for (int i = 0; i < 32; i++)
                    cc[i] -= count[left - 1][i];

            int cnt = 0;
            for (int i = 0; i < 32; i++)
                cnt += (prefix.back()[i] - (left > 0 ? prefix[left - 1][i] : 0)) > 0;
            for (int i = 0; i < 32; i++)
                cnt -= cc[i] > 0;

            while (right < n && cnt > 0)
            {
                for (int i = 0; i < 32; i++)
                    if (count[right][i])
                    {
                        cnt -= cc[i] == 0;
                        cc[i]++;
                    };
                right++;
            };
            ans[left] = max(1, right - left);
        }
        return ans;
    }
};