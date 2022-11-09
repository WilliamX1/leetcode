class Solution
{
  public:
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
    {
        int n = nums.size();
        long long cur = 0;
        vector<long long> answer(n), left(n, -1), right(n, -1), prefix(n, 0);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + (long long)nums[i];

        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] = cur;

            int add = removeQueries[i], l, r;
            if (add > 0 && left[add - 1] != -1)
                l = left[add - 1];
            else
                l = add;
            if (add < n - 1 && right[add + 1] != -1)
                r = right[add + 1];
            else
                r = add;

            // cout << add << ' ' << l << ' ' << r << endl;

            cur = max(cur, prefix[r] - prefix[l] + (long long)nums[l]);

            right[l] = r;
            left[r] = l;
        };

        return answer;
    }
};