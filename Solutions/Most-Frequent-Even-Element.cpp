class Solution
{
  public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (const int &num : nums)
            count[num]++;
        int ans = -1, cnt = 0;
        for (const int &num : nums)
            if (!(num & 1) && (count[num] > cnt || count[num] == cnt && num < ans))
            {
                ans = num;
                cnt = count[num];
            };
        return ans;
    }
};