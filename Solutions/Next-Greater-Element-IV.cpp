class Solution
{
  public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        struct node
        {
            int val;
            int idx;
            node(){};
            node(int val, int idx) : val(val), idx(idx){};
            bool operator>(const node &b) const
            {
                return this->val > b.val;
            };
        };

        priority_queue<node, vector<node>, greater<node>> pque0, pque1;

        int n = nums.size();
        vector<int> answer(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!pque1.empty())
            {
                node t = pque1.top();
                if (t.val < nums[i])
                {
                    answer[t.idx] = nums[i];
                    pque1.pop();
                }
                else
                    break;
            };
            while (!pque0.empty())
            {
                node t = pque0.top();
                if (t.val < nums[i])
                {
                    pque1.push(node(t.val, t.idx));
                    pque0.pop();
                }
                else
                    break;
            };
            pque0.push(node(nums[i], i));
        };
        return answer;
    }
};