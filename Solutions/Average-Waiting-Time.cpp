class Solution
{
  public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int64_t tot_time = 0, cur_time = 0;
        for (const vector<int> &cus : customers)
        {
            int64_t start = cus[0], end = cus[0] + cus[1];
            int64_t true_end = end + (cur_time - start > 0 ? cur_time - start : 0);
            tot_time += true_end - start;
            cur_time = true_end;
        };
        double avg_time = (double)tot_time / customers.size();
        return avg_time;
    };
};