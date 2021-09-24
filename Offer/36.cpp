class Solution {
private:
    Node* adjust(Node* root, int dir) {
        if (root == nullptr) return nullptr;
        Node* tmp_left = adjust(root->left, 0), *tmp_right = adjust(root->right, 1), *ptr, *prev = root;
        if (dir == 0) {
            ptr = tmp_right;
            while (ptr) {
                ptr->left = prev;
                prev->right = ptr;
                prev = ptr;
                ptr = ptr->right; 
            };
            if (tmp_left) tmp_left->right = root;
            root->left = tmp_left;
            return prev;
        } else {
            ptr = tmp_left;
            while (ptr) {
                ptr->right = prev;
                prev->left = ptr;
                prev = ptr;
                ptr = ptr->left;
            };
            if (tmp_right) tmp_right->left = root;
            root->right = tmp_right;
            return prev;
        };
    };
    Node* getMin(Node* root) {
        Node* ptr = root;
        Node* tail = ptr->left;
        while (ptr->left) ptr = ptr->left;
        root = nullptr;
        if (tail) tail->right = ptr; 
        ptr->left = tail;
        return ptr;
    }
public:
    Node* treeToDoublyList(Node* root) {
        Node* new_root = new Node(0x7fffffff, root, nullptr);
        adjust(new_root, 0);
        return root ? getMin(new_root) : nullptr;
    }
};