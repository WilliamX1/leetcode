class Solution
{
  public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> countleft, countright;
        int n = nums.size(), left = -1, right = -1;
        while (left + 1 < n && k)
        {
            k -= !countleft.count(nums[left + 1]);
            countleft[nums[++left]]++;
            countright[nums[++right]]++;
        };

        if (k)
            return 0;

        while (right + 1 < n && countright.count(nums[right + 1]))
            countright[nums[++right]]++;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << "i: " << i << " left: " << left << " right: " << right << endl;
            ans += right - left + 1;
            countleft[nums[i]]--;
            countright[nums[i]]--;
            // cout << "countleft: " << countleft[nums[i]] << " countright: " << countright[nums[i]] << endl;
            if (!countleft[nums[i]])
            {
                // cout << "left: " << left << endl;
                while (left + 1 < n && countleft[nums[left + 1]])
                    countleft[nums[++left]]++;
                // cout << "left: " << left << endl;
                if (left + 1 < n)
                    countleft[nums[++left]]++;
                else
                    break;
            };

            if (!countright[nums[i]])
            {
                while (right + 1 < n && countright[nums[right + 1]])
                    countright[nums[++right]]++;
                if (right + 1 < n)
                    countright[nums[++right]]++;
                else
                    break;
                while (right + 1 < n && countright[nums[right + 1]])
                    countright[nums[++right]]++;
            };
        };
        return ans;
    }
};