class Solution
{
  public:
    // long long _makeSimilar(vector<long long> numscopy, vector<long long> targetcopy, long long &up, long long &down)
    // {
    //     long long ans = 0;

    //     for (int i = 0; i < numscopy.size(); i++)
    //     {
    //         if (numscopy[i] > targetcopy[i])
    //         {
    //             long long tmp = min((numscopy[i] - targetcopy[i]) / 2, max(-up, 0LL));
    //             numscopy[i] -= tmp;
    //             up -= tmp;

    //             up += (numscopy[i] - targetcopy[i]) / 2;
    //             ans += (numscopy[i] - targetcopy[i]) / 2;
    //         }
    //         else if (numscopy[i] < targetcopy[i])
    //         {
    //             long long tmp = min((targetcopy[i] - numscopy[i]) / 2, max(up, 0LL));
    //             numscopy[i] += tmp;
    //             up += tmp;

    //             up -= (targetcopy[i] - numscopy[i]) / 2;
    //             ans += (targetcopy[i] - numscopy[i]) / 2;
    //         }
    //         else
    //         {
    //         };
    //     };
    //     return ans;
    // };
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());

        vector<long long> numscopy, numscopy1;
        vector<long long> targetcopy, targetcopy1;
        for (int &num : nums)
            if (num & 1)
                numscopy.push_back(num);
            else
                numscopy1.push_back(num);
        for (int &num : target)
            if (num & 1)
                targetcopy.push_back(num);
            else
                targetcopy1.push_back(num);

        long long up = 0, down = 0;
        for (int i = 0; i < numscopy.size(); i++)
        {
            if (numscopy[i] > targetcopy[i])
                down += (numscopy[i] - targetcopy[i]) / 2;
            else if (numscopy[i] < targetcopy[i])
                up += (targetcopy[i] - numscopy[i]) / 2;
        }

        for (int i = 0; i < numscopy1.size(); i++)
        {
            if (numscopy1[i] > targetcopy1[i])
                down += (numscopy1[i] - targetcopy1[i]) / 2;
            else if (numscopy1[i] < targetcopy1[i])
                up += (targetcopy1[i] - numscopy1[i]) / 2;
        }
        return up;
    }
};