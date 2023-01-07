class DataStream
{
  public:
    deque<int> dque;
    int total_k, val, k;
    DataStream(int value, int k)
    {
        this->total_k = 0;
        this->k = k;
        this->val = value;
    }

    bool consec(int num)
    {
        total_k += num == val;
        dque.push_back(num);
        if (dque.size() == k + 1)
        {
            total_k -= dque.front() == val;
            dque.pop_front();
        };
        return total_k == k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */