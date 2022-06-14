class Solution
{
  public:
    int sunXor(int x)
    {
        switch (x % 4)
        {
        case 0:
            return x;
        case 1:
            return 1;
        case 2:
            return x + 1;
        case 3:
            return 0;
        default:
            break;
        }
        return 0;
    }
    int xorOperation(int n, int start)
    {
        /*暴力计算*/
        // int ans = 0;
        // for (int i = 0; i < n; i++)
        //     ans ^= start + (i << 1);
        // return ans;
        /*利用异或性质*/
        int s = start >> 1;
        int ans = sunXor(s - 1) ^ sunXor(s + n - 1);
        return ans << 1 | n & start & 1;
    }
};