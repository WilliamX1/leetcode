class Solution
{
  public:
    int minimumOperations(vector<int> &nums)
    {
        set<int> s;
        for (const int &num : nums)
            if (num)
                s.insert(num);
        return s.size();
    }
};