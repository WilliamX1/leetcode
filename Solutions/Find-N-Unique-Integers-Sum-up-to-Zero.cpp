class Solution
{
  public:
    vector<int> sumZero(int n)
    {
        vector<int> v;
        if (n & 1)
        {
            v.push_back(0);
            n--;
        };
        while (n)
        {
            v.push_back(n);
            v.push_back(-n);
            n -= 2;
        };
        return v;
    }
};