class Solution
{
  public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];
        int m = queries.size();
        vector<int> answers(m);
        for (int i = 0; i < m; i++)
            answers[i] = upper_bound(prefix.begin(), prefix.end(), queries[i]) - prefix.begin();
        return answers;
    }
};