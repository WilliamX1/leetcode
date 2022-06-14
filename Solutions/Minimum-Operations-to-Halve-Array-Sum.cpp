class Solution
{
  public:
    int halveArray(vector<int> &nums)
    {
        double tot = 0;
        int64_t ans = 0, tt = 0;
        priority_queue<double, vector<double>, less<double>> pque;
        for (const int64_t &num : nums)
        {
            pque.push((double)num);
            tt += num;
        };
        tot = (double)tt / double(2);
        while (tot > 0)
        {
            double top = pque.top();
            pque.pop();

            ++ans;
            top /= 2;
            tot -= top;
            pque.push(top);
        };
        return ans;
    }
};