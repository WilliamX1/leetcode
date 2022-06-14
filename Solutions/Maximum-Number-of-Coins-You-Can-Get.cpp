class Solution
{
  public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end(), greater<int>());
        int tot = 0, n = piles.size() / 3;
        for (int i = 1; n-- > 0; i += 2)
            tot += piles[i];
        return tot;
    }
};