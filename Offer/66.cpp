class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return vector<int>();

        int len = a.size();
        vector<int> v1(len + 1, 0), v2(len + 1, 0);
        v1[0] = v2[len] = 1;
        for (int i = 0; i < len; i++)
            v1[i + 1] = v1[i] * a[i];
        for (int i = len - 1; i >= 0; i--)
            v2[i] = v2[i + 1] * a[i];
        vector<int> ans(len, 0);
        for (int i = 0; i < len; i++)
            ans[i] = v1[i] * v2[i + 1];
        return ans;
    }
};