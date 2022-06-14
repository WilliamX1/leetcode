class Solution
{
  public:
    vector<double> v;
    Solution(vector<int> &w)
    {
        srand((unsigned)time(0));
        double sum = accumulate(w.begin(), w.end(), 0);
        for (auto ele : w)
        {
            double e = ele;
            v.push_back(e / sum);
        };
        int len = v.size();
        for (int i = 1; i < len; i++)
            v[i] += v[i - 1];
        return;
    };

    int pickIndex()
    {
        double cur = rand() / double(RAND_MAX);
        return lower_bound(v.begin(), v.end(), cur) - v.begin();
    };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */