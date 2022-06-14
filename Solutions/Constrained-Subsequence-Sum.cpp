class Solution
{
  public:
    struct node
    {
        int index;
        int val;
        node(){};
        node(int i, int v) : index(i), val(v){};
    };

    struct cmp
    {
        bool operator()(const node &a, const node &b)
        {
            return a.val < b.val;
        };
    };

    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int ans = nums[0];
        priority_queue<node, vector<node>, cmp> pque;
        pque.push(node(0, nums[0]));

        for (int i = 1; i < nums.size(); i++)
        {
            while (!pque.empty() && i - pque.top().index > k)
                pque.pop();
            int val = nums[i] + max(pque.top().val, 0);
            pque.push(node(i, val));
            ans = max(ans, val);
        }
        return ans;
    }
};