class Solution
{
  public:
    int gcd(int x, int y)
    {
        int tmp;
        while (y)
        {
            tmp = x % y;
            x = y;
            y = tmp;
        };
        return x;
    };

    bool get(vector<int> &two, vector<int> &three, int index, int num)
    {
        while (num > 1)
        {
            if (num % 2 == 0)
            {
                two[index]++;
                num /= 2;
            }
            else if (num % 3 == 0)
            {
                three[index]++;
                num /= 3;
            }
            else
                return false;
        };
        return true;
    };

    int minOperations(vector<int> &numbers)
    {
        int n = numbers.size();
        vector<int> two(n, 0), three(n, 0);

        int cur = numbers[0];
        for (int i = 1; i < n; i++)
            cur = gcd(cur, numbers[i]);

        for (int i = 0; i < n; i++)
            if (!get(two, three, i, numbers[i] / cur))
                return -1;

        return *max_element(two.begin(), two.end()) * n - accumulate(two.begin(), two.end(), 0) +
               *max_element(three.begin(), three.end()) * n - accumulate(three.begin(), three.end(), 0);
    }
};