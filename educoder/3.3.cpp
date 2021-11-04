#include<bits/stdc++.h>
#include <string>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* _buildTree(string inorder, int l_in, int r_in, string postorder, int l_po, int r_po) {
    if (l_po > r_po) return nullptr;

    TreeNode* root = new TreeNode(postorder[r_po]);
    for (int i = l_in; i <= r_in; i++)
        if (root->val == inorder[i]) {
            root->left = _buildTree(inorder, l_in, i - 1, postorder, l_po, l_po + i - l_in - 1);
            root->right = _buildTree(inorder, i + 1, r_in, postorder, r_po - (r_in - i), r_po - 1);
            break;
        };
    return root;
};

TreeNode* buildTree(string inorder, string postorder) {
    return _buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
};

void traverse(string& prev, TreeNode* head) {
    if (head == nullptr) return;

    prev += head->val;
    traverse(prev, head->left);
    traverse(prev, head->right);
    return;
}; 

int main(void){
    string mid = ""; cin >> mid;
    string post = ""; cin >> post;
    /////your code
    TreeNode* head = buildTree(mid, post);
    string prev = "";
    traverse(prev, head);
    std::cout << prev << std::endl;
    ////////
    return 0;
}
