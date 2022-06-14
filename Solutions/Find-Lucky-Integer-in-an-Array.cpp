class Solution
{
  public:
    int findLucky(vector<int> &arr)
    {
        map<int, int> m;
        for (auto ele : arr)
        {
            auto iter = m.find(ele);
            if (iter != m.end())
                iter->second++;
            else
                m.insert(make_pair(ele, 1));
        };
        int ans = -1;
        for (auto ele : m)
            if (ele.first == ele.second)
                ans = ele.first;
        return ans;
    }
};