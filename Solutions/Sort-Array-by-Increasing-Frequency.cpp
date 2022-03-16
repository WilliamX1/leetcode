class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        const int N = 100 - (-100);
        vector<int> v(N + 1, 0);
        for (const int& num : nums)
            v[num + 100]++;
        vector<int> idxs(N + 1);
        iota(idxs.begin(), idxs.end(), 0);
        stable_sort(idxs.begin(), idxs.end(), [v](const int& a, const int& b) {
            return v[a] != v[b] ? v[a] < v[b] : a > b;
        });
        vector<int> ans;
        for (int i = 0; i <= N; i++) {
            while (v[idxs[i]]-- > 0)
                ans.push_back(idxs[i] - 100);
        };
        return ans;
    }
};