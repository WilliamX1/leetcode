class ATM
{
  public:
    vector<long long> counts;
    const int N = 5;
    ATM()
    {
        counts = vector<long long>(N, 0);
    }

    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < N; i++)
            counts[i] += (long long)banknotesCount[i];
        return;
    }

    vector<int> withdraw(int amount)
    {
        int cnt500 = min((long long)amount / 500, counts[4]);
        amount -= 500 * cnt500;
        int cnt200 = min((long long)amount / 200, counts[3]);
        amount -= 200 * cnt200;
        int cnt100 = min((long long)amount / 100, counts[2]);
        amount -= 100 * cnt100;
        int cnt50 = min((long long)amount / 50, counts[1]);
        amount -= 50 * cnt50;
        int cnt20 = min((long long)amount / 20, counts[0]);
        amount -= 20 * cnt20;
        if (amount == 0)
        {
            counts[4] -= cnt500;
            counts[3] -= cnt200;
            counts[2] -= cnt100;
            counts[1] -= cnt50;
            counts[0] -= cnt20;
            return {cnt20, cnt50, cnt100, cnt200, cnt500};
        }
        else
            return {-1};
    };
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */