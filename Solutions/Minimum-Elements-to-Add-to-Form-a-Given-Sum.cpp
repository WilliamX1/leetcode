class Solution
{
  public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        int64_t tot = 0;
        for (const int &num : nums)
            tot += (int64_t)num;
        int64_t target = goal - tot;
        return target ? (abs(target) - 1) / (int64_t)limit + 1 : 0;
    }
};