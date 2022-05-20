class Solution {
public:
    struct cmp {
        bool operator() (const vector<int>& v1, const vector<int>& v2) const {
            return v1[1] < v2[1];
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int& num : nums) counts[num]++;
        priority_queue<vector<int>, vector<vector<int> >, cmp > pque;
        for (auto iter : counts)
            pque.push({iter.first, iter.second});
        vector<int> answer;
        while (k-- > 0) {
            answer.push_back(pque.top()[0]);
            pque.pop();
        };
        return answer;
    }
};