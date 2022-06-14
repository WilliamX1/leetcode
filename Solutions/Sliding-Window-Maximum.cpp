#include <queue>

using namespace std;

class Solution
{
  public:
    struct node
    {
        int val;
        int idx;
        node(){};
        node(int val, int idx) : val(val), idx(idx){};
    };
    struct cmp
    {
        bool operator()(node &a, node &b)
        {
            return a.val < b.val;
        }
    };
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<node, vector<node>, cmp> pque;
        for (int i = 0; i < k; i++)
            pque.push(node(nums[i], i));
        vector<int> ans;
        ans.push_back(pque.top().val);
        for (int i = k; i < nums.size(); i++)
        {
            pque.push(node(nums[i], i));
            while (!pque.empty() && i - pque.top().idx >= k)
                pque.pop();
            ans.push_back(pque.top().val);
        };
        return ans;
    }
};