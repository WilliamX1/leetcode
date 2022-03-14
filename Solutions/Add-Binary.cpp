class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;

        int tot = 0, t = 0;
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            tot = (a[i] - '0') + (b[i] - '0') + t;
            t = tot >= 2;
            ans.insert(ans.begin(), tot % 2 + '0');
        };
        for (int i = min(a.size(), b.size()); i < a.size(); i++) {
            tot = (a[i] - '0') + t;
            t = tot >= 2;
            ans.insert(ans.begin(), tot % 2 + '0');
        };
        for (int i = min(a.size(), b.size()); i < b.size(); i++) {
            tot = (b[i] - '0') + t;
            t = tot >= 2;
            ans.insert(ans.begin(), tot % 2 + '0');
        };

        if (t) ans.insert(ans.begin(), t % 2 + '0');
        
        return ans;
    }
};