class Solution
{
  public:
    vector<int> majorityElement(vector<int> &nums)
    {
        /* 哈希计数 */
        // unordered_map<int, int> m;
        // for (auto& num : nums) {
        //     auto iter = m.find(num);
        //     if (iter == m.end()) m[num] = 1;
        //     else iter->second++;
        // };
        // vector<int> ret;
        // int n = nums.size();
        // for (auto& iter : m) {
        //     if (iter.second > n / 3) ret.push_back(iter.first);
        // };
        // return ret;
        /* 摩尔投票 */
        int ele1 = -1, ele2 = -1;
        int vote1 = 0, vote2 = 0;
        for (auto &num : nums)
        {
            if (vote1 > 0 && num == ele1)
                vote1++;
            else if (vote2 > 0 && num == ele2)
                vote2++;
            else if (vote1 == 0)
            {
                vote1++;
                ele1 = num;
            }
            else if (vote2 == 0)
            {
                vote2++;
                ele2 = num;
            }
            else
            {
                vote1--;
                vote2--;
            };
        };
        vector<int> ret;
        int cnt1 = 0, cnt2 = 0, n = nums.size();
        for (auto &num : nums)
        {
            if (num == ele1)
                cnt1++;
            else if (num == ele2)
                cnt2++;
        };
        if (cnt1 > n / 3)
            ret.push_back(ele1);
        if (cnt2 > n / 3)
            ret.push_back(ele2);
        return ret;
    }
};