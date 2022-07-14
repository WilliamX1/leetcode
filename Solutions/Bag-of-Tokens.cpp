class Solution
{
  public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), left = 0, right = n - 1, ans = 0;
        while (left <= right)
        {
            while (left <= right && power >= tokens[left])
            {
                power -= tokens[left];
                left++;
                ans++;
            };
            if (ans > 0 && left <= right && power + tokens[right] >= tokens[left])
            {
                power += tokens[right] - tokens[left];
                left++;
                right--;
            }
            else
                break;
        };
        return ans;
    }
};