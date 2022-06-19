class Solution
{
  public:
    int minRemainingSpace(vector<int> &N, int V)
    {
        set<int> s;

        for (const int &nn : N)
        {
            set<int> spp = s;
            if (nn <= V)
                s.insert(nn);
            for (const int &p : spp)
                if (p + nn <= V)
                    s.insert(p + nn);
        };
        int ans = V;
        for (const int &p : s)
            ans = min(ans, V - p);
        return ans;
    }
};