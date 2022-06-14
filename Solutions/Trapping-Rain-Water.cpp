class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        if (!len)
            return 0;
        vector<int> leftMax(len, 0), rightMax(len, 0);
        leftMax[0] = height[0], rightMax[len - 1] = height[len - 1];

        for (int i = 1; i < len; i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);
        for (int i = len - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);

        int ans = 0;
        for (int i = 0; i < len; i++)
            ans += min(leftMax[i], rightMax[i]) - height[i];
        return ans;
    }
};