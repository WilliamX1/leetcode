class Bitset {
public:
    vector<bool> v;
    int flag, cnt1;
    Bitset(int size) {
        v.assign(size, 0);
        flag = false;
        cnt1 = 0;
    };
    
    void fix(int idx) {
        if (!flag && v[idx] == 0
            || flag && v[idx] == 1) {
                v[idx] = !v[idx];
                cnt1++;
            };
    }
    
    void unfix(int idx) {
        if (!flag && v[idx] == 1
        || flag && v[idx] == 0) {
            v[idx] = !v[idx];
            cnt1--;
        };
    }
    
    void flip() {
        flag = !flag;
        cnt1 = v.size() - cnt1;
    }
    
    bool all() {
        return cnt1 == v.size();
    }
    
    bool one() {
        return cnt1 > 0;
    }
    
    int count() {
        return cnt1;
    }
    
    string toString() {
        string str = "";
        for (auto num : v) {
            if (flag ^ num) str += "1";
            else str += "0";
        };
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */