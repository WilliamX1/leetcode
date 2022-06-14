class Solution
{
  public:
    int minimumSum(int num)
    {
        vector<int> v;
        while (num > 0)
        {
            v.push_back(num % 10);
            num /= 10;
        };
        sort(v.begin(), v.end(), greater<int>());
        int ans = v[0] + v[1] + 10 * (v[2] + v[3]);

        return ans;
    }
};