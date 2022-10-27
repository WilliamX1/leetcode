class Solution
{
  public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        int n = chargeTimes.size();
        vector<long long> prefix_running_costs(n);
        prefix_running_costs[0] = runningCosts[0];
        for (int i = 1; i < n; i++)
            prefix_running_costs[i] = prefix_running_costs[i - 1] + (long long)runningCosts[i];

        int left = 0, right = 0, ans = 0;

        priority_queue<int, vector<int>, less<int>> pque;

        unordered_map<int, int> pop_count;

        while (left < n)
        {
            // while (right < left)
            // {
            //     pop_count[chargeTimes[right]]++;
            //     right++;
            // };

            while (!pque.empty())
            {
                int front = pque.top();
                if (pop_count[front])
                {
                    pque.pop();
                    pop_count[front]--;
                }
                else
                    break;
            };

            right = max(right, left);

            while (right < n)
            {
                pque.push(chargeTimes[right]);
                long long tot_lose =
                    (long long)pque.top() +
                    (long long)(right - left + 1) *
                        (long long)(prefix_running_costs[right] - prefix_running_costs[left] + runningCosts[left]);
                // cout << left << ' ' << right << ' ' << tot_lose << endl;
                if (tot_lose <= budget)
                {
                    // cout << tot_lose << ' ' << left << ' ' << right << endl;
                    ans = max(ans, right - left + 1);
                    right++;
                }
                else
                {
                    pop_count[chargeTimes[right]]++;
                    break;
                }
            };

            pop_count[chargeTimes[left]]++;
            left++;
        };
        return ans;
    }
};