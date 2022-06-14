class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        /* 在(m-1)*(n-1)次走路中选择(m-1)次向下 */
        uint64_t up = m - 1;
        uint64_t down = m - 1 + n - 1;
        uint64_t res = 1;
        set<int> s;
        for (int i = 1; i <= up; i++)
        {
            s.insert(i);
        };

        for (int i = 0; i < up; i++)
        {
            res *= down - i;
            for (auto ele : s)
            {
                if (res % ele == 0)
                {
                    res /= ele;
                    s.erase(ele);
                };
            };
        };
        return res;
    }
};