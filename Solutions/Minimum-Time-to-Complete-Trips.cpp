class Solution
{
  public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        sort(time.begin(), time.end(), less<int>());
        int64_t left = 0, right = 0x7fffffffffff;
        while (left <= right)
        {
            int64_t mid = (left + right) >> 1;
            int64_t tot = 0;
            for (int64_t i = 0; i < time.size(); i++)
                tot += mid / time[i];
            if (tot >= totalTrips)
                right = mid - 1;
            else
                left = mid + 1;
        };
        return left;
    }
};