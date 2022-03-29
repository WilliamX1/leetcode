class Solution {
public:
    int cal(int n) {
        int ans = 0;
        while (n > 0) {
            ans += pow((n % 10), 2);
            n /= 10;
        };
        return ans;
    };
    bool isHappy(int n) {
        unordered_map<int, bool> umap;
        while (!umap[n] && n > 1) {
            umap[n] = true;
            n = cal(n);
        };
        return n == 1;
    }
};