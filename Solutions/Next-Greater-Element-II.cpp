class Solution
{
  public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int len = nums.size();
        stack<int> s;
        vector<int> v(len, -1);
        for (int i = 2 * len - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i % len])
                s.pop();
            v[i % len] = s.empty() && v[i % len] == -1 ? -1 : s.top();
            s.push(nums[i % len]);
        };
        return v;
    }
};