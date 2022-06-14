class Solution
{
  private:
    vector<int> arr;
    struct node
    {
        int val;
        node *left;
        node *right;
        node(int v, node *l = nullptr, node *r = nullptr) : val(v), left(l), right(r){};
    };
    void insert(node *root, int val)
    {
        if (val < root->val)
        {
            if (!root->left)
                root->left = new node(val);
            else
                insert(root->left, val);
        }
        else
        {
            if (!root->right)
                root->right = new node(val);
            else
                insert(root->right, val);
        };
        return;
    };
    void getPoster(node *root)
    {
        if (root->left)
            getPoster(root->left);
        if (root->right)
            getPoster(root->right);
        arr.push_back(root->val);
        return;
    };

  public:
    bool verifyPostorder(vector<int> &postorder)
    {
        if (postorder.empty())
            return true;
        int root_val = postorder.back(), len = postorder.size();
        node *root = new node(root_val);
        for (int i = len - 2; i >= 0; i--)
        {
            insert(root, postorder[i]);
        };

        if (root)
            getPoster(root);
        return postorder == arr;
    }
};