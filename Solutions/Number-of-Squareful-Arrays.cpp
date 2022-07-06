class Solution
{
  public:
    bool OK(const int &num1, const int &num2)
    {
        int64_t tot = num1 + num2;
        int64_t sqt = sqrt(tot);
        return pow(sqt, 2) == tot;
    };
    void dfs(unordered_map<int, int> &num2cnt, const int &n, const int &last, const int &ct, set<vector<int>> &ans,
             vector<int> &cur)
    {
        if (!ct)
            ans.insert(cur);
        else
        {
            for (auto iter : num2cnt)
            {
                int num = iter.first, cnt = iter.second;
                if (cnt && OK(last, num))
                {
                    num2cnt[num]--;
                    cur.push_back(num);
                    dfs(num2cnt, n, num, ct - 1, ans, cur);
                    cur.pop_back();
                    num2cnt[num]++;
                };
            };
        };
    };
    int numSquarefulPerms(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> havebeen(n, false);
        set<vector<int>> ans;
        unordered_map<int, int> num2cnt;
        for (const int &num : nums)
            num2cnt[num]++;

        vector<int> cur;
        for (auto iter : num2cnt)
        {
            int num = iter.first, cnt = iter.second;
            num2cnt[num]--;
            cur.push_back(num);
            dfs(num2cnt, n, num, n - 1, ans, cur);
            cur.pop_back();
            num2cnt[num]++;
        };
        // for (const vector<int> &v : ans)
        // {
        //     for (const int &num : v)
        //         cout << num << ' ';
        //     cout << endl;
        // }
        return ans.size();
    }
};