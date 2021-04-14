#include <iostream>

using namespace std;

class Trie {
private:
    const static int _nodenum = 26;
    struct TreeNode {
        bool isDst; //是否是一个词的结尾
        TreeNode *next[Trie::_nodenum];
        TreeNode() : isDst(false) {
            for (int i = 0; i < Trie::_nodenum; i++)
                next[i] = nullptr;
        };
    };
    TreeNode *head;
public:
    /** Initialize your data structure here. */
    Trie() {
        /*头结点只有一个，且不存值*/
        head = new TreeNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *cursor = head;
        int len = word.length();
        for (int i = 0; i < len; i++) {
            if (cursor->next[word[i] - 'a'] == nullptr)
                cursor = cursor->next[word[i] - 'a'] = new TreeNode();
            else cursor = cursor->next[word[i] - 'a'];
        };
        cursor->isDst = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *cursor = head;
        int len = word.length();
        for (int i = 0; i < len; i++) {
            if (cursor->next[word[i] - 'a'] == nullptr) return false;
            else cursor = cursor->next[word[i] - 'a'];
        };
        return cursor->isDst == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *cursor = head;
        int len = prefix.length();
        for (int i = 0; i < len; i++) {
            if (cursor->next[prefix[i] - 'a'] == nullptr) return false;
            else cursor = cursor->next[prefix[i] - 'a'];
        };
        return true;
    }
};

int main()
{
    Trie* obj = new Trie();
    obj->insert("apple");
    cout << obj->search("applea") << endl;
    cout << obj->startsWith("applea") << endl;
    cout << obj->search("w");
    return 0;
}