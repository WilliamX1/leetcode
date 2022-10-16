class Solution
{
  public:
    int countDistinctIntegers(vector<int> &nums)
    {
        set<int> s;
        for (const int &num : nums)
            s.insert(num);
        for (int num : nums)
        {

            string str = to_string(num);
            reverse(str.begin(), str.end());
            int tmp = stoll(str);

            s.insert(tmp);
        };
        return s.size();
    }
};