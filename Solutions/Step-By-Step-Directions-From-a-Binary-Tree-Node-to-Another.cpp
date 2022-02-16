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
class Solution {
public:
    bool getPath(TreeNode* root, int value, deque<char>& path) {
        if (root == nullptr) return false;
        if (root->val == value) return true;

        if (getPath(root->left, value, path) == true) {
            path.push_front('L');
            return true;
        } else if (getPath(root->right, value, path) == true) {
            path.push_front('R');
            return true;
        } else return false;
    };
    string getDirections(TreeNode* root, int startValue, int destValue) {
        deque<char> path1, path2;
        getPath(root, startValue, path1);
        getPath(root, destValue, path2);
        while (!path1.empty() && !path2.empty() && path1.front() == path2.front()) {
            path1.pop_front();
            path2.pop_front();
        };

        string str1(path1.size(), 'U'), str2(path2.size(), ' ');
        for (int i = 0; i < str2.size(); i++) {
            str2[i] = path2.front();
            path2.pop_front();
        };
        return str1 + str2;
    }
};