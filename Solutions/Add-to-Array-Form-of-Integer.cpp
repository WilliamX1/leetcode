class Solution
{
  public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int more = 0;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            int tt = num[i] + (k % 10) + more;
            k /= 10;

            num[i] = tt % 10;
            more = tt / 10;
        };
        while (k > 0 || more > 0)
        {
            int tt = k % 10 + more;
            k /= 10;

            num.insert(num.begin(), tt % 10);
            more = tt / 10;
        };
        return num;
    }
};