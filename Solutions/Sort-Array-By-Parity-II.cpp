class Solution
{
  public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int ptrodd = 0, ptreven = 0, n = nums.size();
        while (ptrodd < n && ptreven < n)
        {
            while (ptrodd < n)
            {
                if (ptrodd & 1)
                {
                    if (nums[ptrodd] & 1)
                        ptrodd++;
                    else
                        break;
                }
                else
                    ptrodd++;
            };
            while (ptreven < n)
            {
                if ((ptreven & 1) == 0)
                {
                    if ((nums[ptreven] & 1) == 0)
                        ptreven++;
                    else
                        break;
                }
                else
                    ptreven++;
            };
            if (ptrodd < n && ptreven < n)
            {
                swap(nums[ptrodd], nums[ptreven]);
            };
        };
        return nums;
    }
};