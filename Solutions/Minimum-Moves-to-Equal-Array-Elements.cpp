class Solution
{
  public:
    int minMoves(vector<int> &nums)
    {
        /* acc + x * (n - 1) = (m + x) * n
         */
        int acc = accumulate(nums.begin(), nums.end(), 0), m = *min_element(nums.begin(), nums.end()), n = nums.size();
        return acc - m * n;
    }
};