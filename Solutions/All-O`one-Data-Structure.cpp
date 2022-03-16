#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

class AllOne {
public:
    struct node {
        string str;
        int cnt;
        node() {};
        node(string s, int c) : str(s), cnt(c) {};
    };
    struct cmp_less {
        bool operator()(const node& a, const node& b) {
            return a.cnt > b.cnt;
        };
    };
    struct cmp_greater {
        bool operator()(const node& a, const node& b) {
            return a.cnt < b.cnt;
        };
    };
    unordered_map<string, int> umap;
    priority_queue<node, vector<node>, cmp_less> pque_less;
    priority_queue<node, vector<node>, cmp_greater> pque_greater;

    AllOne() {

    }
    
    void inc(string key) {
        umap[key]++;
        pque_less.push(node(key, umap[key]));
        pque_greater.push(node(key, umap[key]));
    };
    
    void dec(string key) {
        umap[key]--;
    };
    
    string getMaxKey() {
        while (!pque_greater.empty() && pque_greater.top().cnt != umap[pque_greater.top().str]) pque_greater.pop();
        if (pque_greater.empty()) return "";
        else return pque_greater.top().str;
    }
    
    string getMinKey() {
        while (!pque_less.empty() && pque_less.top().cnt != umap[pque_less.top().str]) pque_less.pop();
        if (pque_less.empty()) return "";
        else return pque_less.top().str;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */