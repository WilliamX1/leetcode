class Solution {
public:
    int get(const int& root, const vector<int>& left, const vector<int>& right, vector<int>& leftsons, vector<int>& rightsons) {
        if (left[root] == -1 && right[root] == -1) return 1;

        if (left[root] != -1) leftsons[root] = get(left[root], left, right, leftsons, rightsons);
        if (right[root] != -1) rightsons[root] = get(right[root], left, right, leftsons, rightsons);

        return leftsons[root] + rightsons[root] + 1;
    };

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> leftsons(n, 0), rightsons(n, 0);
        vector<int> left(n, -1), right(n, -1);

        for (int i = 1; i < n; i++)
            if (left[parents[i]] != -1) right[parents[i]] = i;
            else left[parents[i]] = i;

        get(0, left, right, leftsons, rightsons);

        int64_t ans = 0, tot = 0;
        for (int i = 0; i < n; i++) {
            int64_t tmp = (int64_t) max(1, leftsons[i]) * (int64_t) max(1, rightsons[i]);
            if (parents[i] != -1) {
                tmp *= (int64_t) (n - leftsons[i] - rightsons[i] - 1);
            };
            if (tmp > ans) {
                ans = tmp;
                tot = 1;
            } else if (tmp == ans) tot++;
            else {};
        };
        return tot;
    }
};