class Solution
{
  public:
    int minIncrementForUnique(vector<int> &nums)
    {
        unordered_map<int, bool> counts;

        sort(nums.begin(), nums.end());

        int start = nums[0], ans = 0;

        for (const int &num : nums)
        {
            if (counts[num])
            {
                ans += max(0, start - num);
                start = max(start, num);
                while (counts[start])
                {
                    start++;
                    ans++;
                };
                counts[start] = true;
                // cout << num << ' ' << start << ' ' << endl;
            }
            else
                counts[num] = true;
        };
        return ans;
    }
};