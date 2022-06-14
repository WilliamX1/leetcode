class Solution
{
  public:
    bool isPossible(vector<int> &target)
    {
        if (target.size() == 1)
            return target[0] == 1;

        int64_t tot = 0;
        priority_queue<int, vector<int>, less<int>> pque;
        for (const int &t : target)
        {
            tot += (int64_t)t;
            pque.push(t);
        };

        while (!pque.empty() && pque.top() > 1)
        {
            int64_t p = pque.top();
            pque.pop();

            tot -= p;
            if (p - tot < 1)
                return false;
            else if (pque.empty())
            {
                p -= tot;
                tot += p;
                pque.push(p);
            }
            else
            {
                int64_t s = pque.top();
                p -= ((p - s - 1) / tot + 1) * tot;
                tot += p;
                if (p >= 1)
                    pque.push(p);
                else
                    return false;
            };
        };
        return true;
    }
};