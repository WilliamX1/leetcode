/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Codec {
    string flag = "N";
    char queto = '|';
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = ""; res += queto;
        deque<TreeNode*> q;
        if (root) q.push_back(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop_front();
            if (cur) {
                res += to_string(cur->val);
                q.push_back(cur->left);
                q.push_back(cur->right);
            } else res += flag;
            res += queto;
        };
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> stringList;
        int start = 1, end = 1, len = data.size();
        while (end < len) {
            while (end < len && data[end] != queto) end++;
            stringList.push_back(data.substr(start, end - start));
            start = end = end + 1; 
        };

        TreeNode* root = stringList.empty() ? nullptr : new TreeNode(stoi(stringList.front()));
        int idx = 0;
        deque<TreeNode*> q;
        if (root) q.push_back(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop_front();
            string left_val = stringList[++idx], right_val = stringList[++idx];
            
            TreeNode* left = cur->left = left_val != flag ? new TreeNode(stoi(left_val)) : nullptr;
            TreeNode* right = cur->right = right_val != flag ? new TreeNode(stoi(right_val)) : nullptr;
            if (left) q.push_back(left);
            if (right) q.push_back(right);
        };
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));