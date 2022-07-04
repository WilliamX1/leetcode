class Solution
{
  public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int base = 1e6;
        vector<bool> nums(2 * base + 1, false);

        for (const int &num : arr)
            nums[num + base] = true;

        vector<vector<int>> answer;

        int left = 0, right, gap;
        while (left < nums.size() && !nums[left])
            left++;
        right = left + 1;
        while (right < nums.size() && !nums[right])
            right++;

        gap = right - left;
        answer.push_back({left - base, right - base});

        while (true)
        {
            left = right++;
            while (right < nums.size() && !nums[right])
                right++;
            if (right >= nums.size())
                break;
            else if (right - left < gap)
            {
                gap = right - left;
                answer.clear();
                answer.push_back({left - base, right - base});
            }
            else if (right - left == gap)
                answer.push_back({left - base, right - base});
            else
                continue;
        };
        return answer;
    }
};