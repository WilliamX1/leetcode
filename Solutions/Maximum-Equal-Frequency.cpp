class Solution
{
  public:
    int maxEqualFreq(vector<int> &nums)
    {
        unordered_map<int, int> num2count;
        unordered_map<int, int> count2cc;

        int ans = 0, n = nums.size(), tt = 0;
        count2cc[0] = n;
        for (int i = 0; i < n; i++)
        {
            if (!num2count.count(nums[i]))
                tt++;

            count2cc[num2count[nums[i]]]--;
            count2cc[++num2count[nums[i]]]++;

            if (!(tt - 1))
                ans = max(ans, i + 1);

            else if (tt == i + 1)
                ans = max(ans, i + 1);

            else if ((i + 1 - 1) % (tt - 1) == 0 && (count2cc[(i + 1 - 1) / (tt - 1)] == tt - 1))
                ans = max(ans, i + 1);

            else if ((i + 1 - 1) % tt == 0 && (count2cc[(i + 1 - 1) / tt] == tt - 1))
                ans = max(ans, i + 1);
        };
        return ans;
    }
};