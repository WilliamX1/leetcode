class Solution
{
  public:
    struct node
    {
        int t;
        int x;
        int y;
        int val;
        node(){};
        node(int t, int x, int y, int val) : x(x), y(y), t(t), val(val){};
        bool operator>(const node &other) const
        {
            return val < other.val;
        };
    };
    int getMaximumNumber(vector<vector<int>> &moles)
    {
        sort(moles.begin(), moles.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
        priority_queue<node, vector<node>, greater<node>> pque;
        pque.push(node(0, 1, 1, 0));

        int ans = 0;
        for (const vector<int> &mole : moles)
        {
            int t = mole[0], x = mole[1], y = mole[2];
            vector<node> tmp;
            while (!pque.empty())
            {
                node top = pque.top();
                ans = max(ans, top.val);

                // if (t - top.t > 4) pque.pop();
                // else
                if (t - top.t < abs(x - top.x) + abs(y - top.y))
                {
                    tmp.push_back(top);
                    pque.pop();
                }
                else
                {
                    pque.push(node(t, x, y, top.val + 1));
                    break;
                };
            };
            for (const node &t : tmp)
                pque.push(t);
        };

        while (!pque.empty())
        {
            ans = max(ans, pque.top().val);
            pque.pop();
        };

        return ans;
    }
};