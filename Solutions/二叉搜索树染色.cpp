/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int blue = 0, red = 1;
    struct node {
        TreeNode* treenode;
        int color;
        int time;
        int leftcolor;
        int lefttime;
        int rightcolor;
        int righttime;
        node* left;
        node* right;
        node () {};
        node (TreeNode* treenode, int color, int time, node* left = nullptr, node* right = nullptr) 
        : treenode(treenode), color(color), time(time), left(left), right(right), lefttime(-1), righttime(-1) {}
    };
    void build (TreeNode* root, node* newroot) {
        if (root == NULL) return;
        else {
            if (root->left) {
                newroot->left = new node(root->left, blue, -1);
                build(root->left, newroot->left);
            };
            if (root->right) {
                newroot->right = new node(root->right, blue, -1);
                build(root->right, newroot->right);
            };
        };
    };
    void update(node* root, int left, int right, int color, int time) {
        if (root == NULL) return;

        TreeNode* treenode = root->treenode;
        int val = treenode->val;
        if (left < val && val < right) {
            root->color = color;
            root->time = time;
            update(root->left, left, right, color, time);
            update(root->right, left, right, color, time);
        } else if (val == left) {
            root->color = color;
            root->time = time;
            update(root->right, left, right, color, time);
        } else if (val == right) {
            root->color = color;
            root->time = time;
            update(root->left, left, right, color, time);
        }
        else if (val < left) {
            update(root->right, left, right, color, time);
        } else if (val > right) {
            update(root->left, left, right, color, time);
        };
        return;
    };

    int getsum(node* root, int fathercolor, int fathertime) {
        if (root == NULL) return 0;

        int ans = 0;
        // cout << root->treenode->val << ' ' << root->color << ' ' << root->time << ' ' << root->rightcolor << ' ' << root->righttime << endl;
        // if (fathertime > root->time) {
        //     root->color = fathercolor;
        //     root->time = fathertime;
        // };

        return root->color + getsum(root->left, root->leftcolor, root->lefttime) + getsum(root->right, root->rightcolor, root->righttime);
    };
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        node* newroot = new node(root, blue, -1);
        build(root, newroot); 
        int time = 0;
        for (const vector<int> o : ops) {
            int type = o[0], x = o[1], y = o[2];
            update(newroot, x, y, type, time);
            time++;
        };
        return getsum(newroot, 0, -1);
    }
};