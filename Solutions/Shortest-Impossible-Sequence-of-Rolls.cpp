class Solution
{
  public:
    int shortestSequence(vector<int> &rolls, int k)
    {
        set<int> s;
        int ans = 0;
        for (const int &roll : rolls)
        {
            s.insert(roll);
            if (s.size() == k)
            {
                ans++;
                s.clear();
            };
        };
        return ans + 1;
    }
};