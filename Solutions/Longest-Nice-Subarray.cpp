class Solution
{
  public:
    int longestNiceSubarray(vector<int> &nums)
    {
        vector<int> v(32, 0);
        int left = 0, right = 0, n = nums.size(), ans = 0;
        while (right < n)
        {
            int num = nums[right];

            for (int i = 0; i < 32; i++)
                if ((num >> i) & 1)
                    v[i]++;

            bool flag = false;
            for (int i = 0; i < 32; i++)
                if (v[i] > 1)
                    flag = true;
            while (flag)
            {
                int num = nums[left];
                left++;
                for (int i = 0; i < 32; i++)
                    if ((num >> i) & 1)
                        v[i]--;

                flag = false;
                for (int i = 0; i < 32; i++)
                    if (v[i] > 1)
                        flag = true;
            };
            ans = max(ans, right - left + 1);
            right++;
        };
        return ans;
    }
};