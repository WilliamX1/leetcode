class Solution
{
  public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> counts;
        for (const int &task : tasks)
        {
            counts[task]++;
        };

        int ans = 0;
        for (const auto iter : counts)
        {
            int num = iter.second;
            int cnt3 = num / 3, cnt2 = (num - cnt3 * 3) / 2;
            if (cnt3 * 3 + cnt2 * 2 == num)
                ans += cnt3 + cnt2;
            else if (cnt3 > 0)
            {
                cnt3--;
                cnt2 = (num - cnt3 * 3) / 2;
                if (cnt3 * 3 + cnt2 * 2 == num)
                    ans += cnt3 + cnt2;
                else
                    return -1;
            }
            else
                return -1;
        };
        return ans;
    }
};