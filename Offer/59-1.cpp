class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n) return vector<int>();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) q.emplace(nums[i], i);
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; i++) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) q.pop();
            ans.push_back(q.top().first);
        }
        return ans;
    }
};