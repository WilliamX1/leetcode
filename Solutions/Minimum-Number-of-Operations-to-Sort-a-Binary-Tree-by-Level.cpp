/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  public:
    int minimumOperations(TreeNode *root)
    {
        struct node
        {
            TreeNode *value;
            int level;
            node(){};
            node(TreeNode *v, int l) : value(v), level(l){};
        };

        deque<node> dque;

        int ans = 0, cur_level = 0;
        dque.push_back(node(root, 0));

        while (!dque.empty())
        {
            vector<int> v;
            unordered_map<int, int> val2index;
            int idx = 0;
            while (!dque.empty() && dque.front().level == cur_level)
            {
                node t = dque.front();
                dque.pop_front();

                v.push_back(t.value->val);
                val2index[t.value->val] = idx++;
                if (t.value->left)
                    dque.push_back(node(t.value->left, t.level + 1));
                if (t.value->right)
                    dque.push_back(node(t.value->right, t.level + 1));
            };
            cur_level++;

            vector<int> vv = v;
            sort(vv.begin(), vv.end());

            for (int i = 0; i < idx; i++)
            {
                if (v[i] != vv[i])
                {
                    ans++;

                    int v_index = val2index[vv[i]];
                    val2index[v[i]] = v_index;

                    swap(v[i], v[v_index]);
                };
            };
        };
        return ans;
    }
};