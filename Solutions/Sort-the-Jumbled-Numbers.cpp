class Solution
{
  public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<int> idx(nums.size());
        iota(idx.begin(), idx.end(), 0);
        stable_sort(idx.begin(), idx.end(), [&mapping, &nums](const int &a, const int &b) {
            long long tmp_a = nums[a], tmp_b = nums[b];
            long long map_a = 0, map_b = 0;

            long long base = 1;
            if (tmp_a == 0)
                map_a = mapping[0];
            while (tmp_a > 0)
            {
                map_a += base * (long long)mapping[tmp_a % 10];
                tmp_a /= 10;
                base *= 10;
            };

            base = 1;
            if (tmp_b == 0)
                map_b = mapping[0];
            while (tmp_b > 0)
            {
                map_b += base * (long long)mapping[tmp_b % 10];
                tmp_b /= 10;
                base *= 10;
            };

            return map_a == map_b ? a < b : map_a < map_b;
        });
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
            ans[i] = nums[idx[i]];
        return ans;
    }
};