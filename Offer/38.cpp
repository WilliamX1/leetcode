class Solution {
private:
    set<string> ans;
    bool get(int flag, int idx) { return (flag >> idx) & 1; };
    void dfs(const string str, string cur, int flag) {
        if (str.size() == cur.size()) {
            ans.insert(cur);
            return;
        };
        for (int i = 0; i < str.size(); i++) {
            if (!get(flag, i)) 
                dfs(str, cur + str[i], flag | (1 << i));
        };
        return;
    }
public:
    vector<string> permutation(string s) {
        dfs(s, "", 0);
        // sort(ans.begin(), ans.end());
        // auto iter = ans.begin(); ++iter;
        // while (iter != ans.end()) {
        //     if ((*iter) == *(iter - 1)) ans.erase(iter);
        //     else iter++;
        // };
        vector<string> res;
        auto iter = ans.begin();
        while (iter != ans.end()) {
            res.push_back(*iter);
            iter++;
        };
        return res;
    };
};