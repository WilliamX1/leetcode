class Solution
{
  public:
    int destroyTargets(vector<int> &nums, int space)
    {
        unordered_map<int, int> count, present;
        for (const int &num : nums)
        {
            if (present.count(num % space))
                present[num % space] = min(present[num % space], num);
            else
                present[num % space] = num;
            count[num % space]++;
        };
        int ans = 1e9, cnt = 0;
        for (auto &iter : count)
            if (iter.second > cnt || iter.second == cnt && present[iter.first] < ans)
            {
                cnt = iter.second;
                ans = present[iter.first];
            };
        return ans;
    }
};