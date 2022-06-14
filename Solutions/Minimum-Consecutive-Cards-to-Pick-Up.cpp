class Solution
{
  public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> indexs;
        int ans = 0x7fffffff;
        for (int i = 0; i < cards.size(); i++)
        {
            if (indexs.count(cards[i]))
                ans = min(ans, i - indexs[cards[i]] + 1);
            indexs[cards[i]] = i;
        };
        return ans == 0x7fffffff ? -1 : ans;
    }
};