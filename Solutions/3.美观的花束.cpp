class Solution
{
  public:
    int beautifulBouquet(vector<int> &flowers, int cnt)
    {
        unordered_map<int, int> post;
        int n = flowers.size();
        int last = -1, cur = -1, ans = 0, mod = 1e9 + 7;
        while (++cur < n)
        {
            post[flowers[cur]]++;
            while (post[flowers[cur]] > cnt)
                post[flowers[++last]]--;
            ans = (ans + (cur - last)) % mod;
            // cout << ans << ' ';
        };
        return ans;
    }
};