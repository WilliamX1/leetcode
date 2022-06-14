class Solution
{
  public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> counts;
        for (const vector<int> &num : nums)
        {
            for (const int &nn : num)
            {
                counts[nn]++;
            };
        };
        vector<int> answer;
        for (const auto &iter : counts)
        {
            if (iter.second >= n)
            {
                answer.push_back(iter.first);
            };
        };
        sort(answer.begin(), answer.end());
        return answer;
    }
};