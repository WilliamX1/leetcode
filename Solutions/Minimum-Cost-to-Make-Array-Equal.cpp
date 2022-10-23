class Solution
{
  public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        struct node
        {
            long long num;
            long long cc;
            node(){};
            node(long long num, long long cc) : num(num), cc(cc){};
        };

        int n = nums.size();
        vector<node> v;
        for (int i = 0; i < n; i++)
            v.emplace_back(nums[i], cost[i]);

        sort(v.begin(), v.end(), [](const node &a, const node &b) { return a.num < b.num; });

        vector<long long> cost_prefix(n);
        cost_prefix[0] = v[0].cc;
        for (int i = 1; i < n; i++)
            cost_prefix[i] = cost_prefix[i - 1] + v[i].cc;

        long long ans = 1e18, cur = 0;
        for (int i = 0; i < n; i++)
            cur += v[i].cc * v[i].num;

        ans = min(ans, cur);

        int ptr = 0;
        for (int i = 1; i < 1e6 + 7; i++)
        {
            while (ptr < n && v[ptr].num < i)
                ptr++;
            cur += ptr > 0 ? cost_prefix[ptr - 1] : 0;
            cur -= cost_prefix[n - 1] - (ptr > 0 ? cost_prefix[ptr - 1] : 0);
            ans = min(ans, cur);
        };
        return ans;
    }
};