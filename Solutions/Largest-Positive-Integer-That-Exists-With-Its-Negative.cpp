class Solution
{
  public:
    int findMaxK(vector<int> &nums)
    {
        set<int> s;
        for (const int &num : nums)
            s.insert(num);

        int ans = 0;
        for (const int &num : s)
            if (s.count(-num) && num > ans)
                ans = num;
        return ans ? ans : -1;
    }
};