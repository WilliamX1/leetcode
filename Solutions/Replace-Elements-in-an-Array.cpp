class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> num2index;
        for (int i = 0; i < nums.size(); i++) 
            num2index[nums[i]] = i;
        for (vector<int> ope : operations) {
            int num = ope[0], newNum = ope[1];
            num2index[newNum] = num2index[num];
            nums[num2index[num]] = newNum;
        };
        return nums;
    }
};