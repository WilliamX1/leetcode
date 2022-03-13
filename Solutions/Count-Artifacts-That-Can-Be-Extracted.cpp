class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        map<vector<int>, bool> m;
        for (vector<int>& d : dig) m[d] = true;
        int ans = 0;
        for (vector<int>& a : artifacts) {
            int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];
            bool flag = true;
            for (int i = r1; i <= r2; i++)
                for (int j = c1; j <= c2; j++)
                    if (m.find({i, j}) == m.end() || !m[{i, j}])
                        flag = false;
            ans += flag;
        };
        return ans;
    }
};