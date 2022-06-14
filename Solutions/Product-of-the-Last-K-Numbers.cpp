class ProductOfNumbers
{
  public:
    vector<int> v;
    const int N = 200;
    int cnt = 0, mul = 1;
    vector<int> mul_arr;
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        v.push_back(num);

        mul *= num;
        if (++cnt == N)
        {
            mul_arr.push_back(mul);
            cnt = 0;
            mul = 1;
        };
    }

    int getProduct(int k)
    {
        if (k >= N)
        {
            int c = (k - cnt) / N, more = k - cnt - c * N;
            int ans = 1;
            for (int i = 1; i <= cnt; i++)
                ans *= v[v.size() - i];
            for (int i = 1; i <= c; i++)
                ans *= mul_arr[mul_arr.size() - i];

            for (int i = 1; i <= more; i++)
                ans *= v[v.size() - cnt - c * N - i];
            return ans;
        }
        else
        {
            int ans = 1;
            for (int i = 1; i <= k; i++)
                ans *= v[v.size() - i];
            return ans;
        };
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */