class Solution {
public:
    void dfs(string& s, const int& n, const int& idx, int tot, set<string> & res) {
        if (idx == n) {
            if (tot != 0) return;

            int cnt = 0, flag = true;
            for (int i = 0; i < n; i++) {
                if (s[i] == '(') cnt++;
                else if (s[i] == ')') {
                    if (cnt > 0) cnt--;
                    else {
                        flag = false;
                        break;
                    };
                } else continue;
            };
            if (flag && cnt == 0) res.insert(s);
            return;
        };

        dfs(s, n, idx + 1, tot, res);

        if ((s[idx] == '(' || s[idx] == ')') && tot > 0) {
            char tmp = s[idx];
            s[idx] = '0';
            dfs(s, n, idx + 1, tot - 1, res);
            s[idx] = tmp;
        };
    };
    vector<string> removeInvalidParentheses(string s) {
        int tot = 0;
        stack<char> stk;
        for (char ch : s) {
            if (ch == '(') stk.push(ch);
            else if (ch == ')') {
                if (stk.empty()) tot++;
                else stk.pop();
            } else continue;
        };
        tot += stk.size();

        set<string> res;
        dfs(s, s.size(), 0, tot, res);

        set<string> res_nocopy;
        for (string s : res) {
            for (auto iter = s.begin(); iter != s.end();)
                if (*iter == '0') iter = s.erase(iter);
                else iter++;
            res_nocopy.insert(s);
        };
        vector<string> vres;
        for (const string s : res_nocopy)
            vres.push_back(s);
        return vres;
    }
};