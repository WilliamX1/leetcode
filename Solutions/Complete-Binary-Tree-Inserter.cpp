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
class CBTInserter {
public:
    TreeNode* rt;
    CBTInserter(TreeNode* root) {
        rt = root;
    };
    
    int insert(int val) {
        deque<TreeNode*> dq;
        dq.push_back(rt);

        while (!dq.empty()) {
            TreeNode* front = dq.front();
            dq.pop_front();
            if (front->left == nullptr) {
                front->left = new TreeNode(val);
                return front->val;
            };
            if (front->right == nullptr) {
                front->right = new TreeNode(val);
                return front->val;
            };
            dq.push_back(front->left);
            dq.push_back(front->right);
        };
        return -1;
    };
    
    TreeNode* get_root() {
        return rt;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */