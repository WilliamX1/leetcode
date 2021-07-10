#include <bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    struct node
    {
        /* data */
        string val;
        int timestamp;
        node() {};
        node(string str, int tstp) : val(str), timestamp(tstp) {};
    };
    unordered_map<string, vector<node>> m;
    TimeMap() {};
    
    void set(string key, string value, int timestamp) {
        auto iter = m.find(key);
        if (iter == m.end()) {
            m.insert(make_pair(key, vector<node>()));
            iter = m.find(key);
        };
        (iter->second).push_back(node(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        auto iter = m.find(key);
        if (iter == m.end()) return "";
        else {
            auto it = (iter->second).rbegin();
            while (it != (iter->second).rend()) {
                if (it->timestamp > timestamp) it++;
                else break;
            };
            return it == (iter->second).rend() ? "" : it->val;
        };
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */