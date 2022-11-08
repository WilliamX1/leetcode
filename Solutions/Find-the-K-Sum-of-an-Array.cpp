class Solution
{
  public:
    long long kSum(vector<int> &nums, int k)
    {
        long long ans = 0, n = nums.size();
        for (const int &num : nums)
            ans += (long long)max(0, num);
        for (int &num : nums)
            num = abs(num);
        sort(nums.begin(), nums.end());

        // for (const int &num : nums)
        //     cout << num << ' ';
        // cout << endl;

        struct node
        {
            int index;
            long long sum;
            node(){};
            node(int index, long long sum) : index(index), sum(sum){};
            bool operator>(const node &other) const
            {
                return this->sum > other.sum;
            };
        };

        priority_queue<node, vector<node>, greater<node>> pque;
        pque.push(node(0, nums[0]));

        if (k == 1)
            return ans;
        else
            k--;

        while (--k)
        {
            node t = pque.top();
            pque.pop();

            int index = t.index;
            long long sum = t.sum;

            cout << index << ' ' << sum << endl;

            if (index < n - 1)
            {
                pque.push(node(index + 1, sum + (long long)nums[index + 1] - (long long)nums[index]));
                pque.push(node(index + 1, sum + (long long)nums[index + 1]));
            };
        };
        return ans - pque.top().sum;
    }
};