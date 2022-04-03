class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            answer.insert(answer.begin() + index[i], nums[i]);
        };
        return answer;
    }
};