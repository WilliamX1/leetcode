class Solution
{
  public:
    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(),
             [](const int &a, const int &b) { return to_string(a) + to_string(b) < to_string(b) + to_string(a); });
        string ans = "";
        for (auto num : nums)
            ans += to_string(num);
        return ans;
    }
};