class RLEIterator
{
  public:
    vector<int64_t> encoding;
    vector<int64_t> index;
    int64_t tt = 0;
    RLEIterator(vector<int> &encoding)
    {
        for (int64_t i = 0; i < encoding.size(); i += 2)
            if (encoding[i])
            {
                this->index.push_back((index.empty() ? 0 : index.back()) + encoding[i]);
                this->encoding.push_back(encoding[i + 1]);
            };
        this->encoding.push_back(-1);

        for (const int64_t &num : index)
            cout << num << ' ';
        cout << endl;
        for (const int64_t &num : this->encoding)
            cout << num << ' ';
        cout << endl;
    };

    int next(int n)
    {
        tt += (int64_t)n;
        int64_t idx = lower_bound(this->index.begin(), this->index.end(), tt) - this->index.begin();
        cout << tt << ' ' << idx << endl;
        return encoding[idx];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int64_t param_1 = obj->next(n);
 */