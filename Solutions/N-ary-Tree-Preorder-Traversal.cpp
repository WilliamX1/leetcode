/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
  public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;

        if (root == nullptr)
            return ans;
        else
        {
            ans.push_back(root->val);

            for (Node *child : root->children)
            {
                vector<int> tmp = preorder(child);
                ans.insert(ans.end(), tmp.begin(), tmp.end());
            };
        };
        return ans;
    }
};