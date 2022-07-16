class MovingAverage
{
  public:
    deque<int> q;
    int tot = 0, size;
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        this->size = size;
    };

    double next(int val)
    {
        tot += val;
        q.push_back(val);
        // cout << q.size() << ' ' << size << endl;
        if (q.size() > size)
        {
            tot -= q.front();
            q.pop_front();
        };
        // cout << val << ' ' << tot << endl;
        return (double)tot / (double)q.size();
    };
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */