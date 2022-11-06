class Solution
{
  public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size(), left = 0, right = n - 1;

        struct node
        {
            bool left;
            int index;
            int cost;
            node(){};
            node(bool left, int index, int cost) : left(left), index(index), cost(cost){};
            bool operator>(const node &other) const
            {
                return this->cost == other.cost ? this->index > other.index : this->cost > other.cost;
            };
        };

        priority_queue<node, vector<node>, greater<node>> pque;
        unordered_map<int, int> havebeen;

        while (left < candidates)
        {
            pque.push(node(true, left, costs[left]));
            left++;
        };

        while (n - right <= candidates)
        {
            pque.push(node(false, right, costs[right]));
            right--;
        };

        long long ans = 0;
        while (k > 0)
        {
            node t = pque.top();
            pque.pop();

            // cout << k << ' ' << t.cost << endl;

            if (havebeen[t.index])
                continue;
            else
            {
                havebeen[t.index]++;
                k--;

                ans += (long long)t.cost;
                if (t.left && left < n)
                {
                    pque.push(node(true, left, costs[left]));
                    left++;
                }
                else if (!t.left && right >= 0)
                {
                    pque.push(node(false, right, costs[right]));
                    right--;
                };
            };
        };
        return ans;
    }
};