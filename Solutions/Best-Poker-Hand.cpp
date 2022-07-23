class Solution
{
  public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        // "Flush"：同花，五张相同花色的扑克牌。
        // "Three of a Kind"：三条，有 3 张大小相同的扑克牌。
        // "Pair"：对子，两张大小一样的扑克牌。
        // "High Card"：高牌，五张大小互不相同的扑克牌。
        int n = 5;
        bool flag = true;
        for (int i = 1; i < n; i++)
            if (suits[i] != suits[i - 1])
                flag = false;
        if (flag)
            return "Flush";
        else
            flag = true;

        sort(ranks.begin(), ranks.end());
        int tt = 1, ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (ranks[i] == ranks[i - 1])
            {
                tt++;
                ans = max(ans, tt);
            }
            else
                tt = 1;
        };
        if (ans >= 3)
            return "Three of a Kind";
        else if (ans == 2)
            return "Pair";
        else
            return "High Card";
    };
};