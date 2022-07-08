class Solution
{
  public:
    int n = 12, answer = INT32_MAX;
    void dfs(vector<int> &nums, const int &index, const int &ans)
    {
        if (index == n)
            answer = min(answer, ans);
        else if (ans >= answer)
            return;
        else if (!nums[index])
            return dfs(nums, index + 1, ans);
        else
        {
            for (int i = index + 1; i < n; i++)
            {
                nums[i] += nums[index];
                dfs(nums, index + 1, ans + 1);
                nums[i] -= nums[index];
            };
            return;
        };
    }
    int minTransfers(vector<vector<int>> &distributions)
    {
        vector<int> nums(n, 0);
        for (const vector<int> &v : distributions)
        {
            nums[v[0]] -= v[2];
            nums[v[1]] += v[2];
        };

        dfs(nums, 0, 0);
        return answer;
    }
};