class Solution
{
  public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        for (vector<int> &q : queries)
        {
            int a1 = q[0], a2 = q[1], cnt = 1;
            while (a1 != a2)
            {
                if (a1 > a2)
                    a1 >>= 1;
                else
                    a2 >>= 1;
                cnt++;
            }
            ans.push_back(cnt);
        };
        return ans;
    }
};