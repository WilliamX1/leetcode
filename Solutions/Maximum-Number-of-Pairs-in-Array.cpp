class Solution
{
  public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> counts;
        for (const int &num : nums)
            counts[num]++;
        vector<int> answer(2, 0);
        for (auto iter : counts)
        {
            answer[0] += (iter.second) / 2;
            answer[1] += (iter.second) % 2;
        };
        return answer;
    }
};