typedef long long LL;

class Solution
{
    const LL maxn = 1000005, mod = 1e9 + 7;
    vector<LL> Jc = vector<LL>(maxn);
    void calJc() //求maxn以内的数的阶乘
    {
        Jc[0] = Jc[1] = 1;
        for (LL i = 2; i < maxn; i++)
            Jc[i] = Jc[i - 1] * i % mod;
    }
    /*
    //拓展欧几里得算法求逆元
    void exgcd(LL a, LL b, LL &x, LL &y)    //拓展欧几里得算法
    {
        if(!b) x = 1, y = 0;
        else
        {
            exgcd(b, a % b, y, x);
            y -= x * (a / b);
        }
    }
    LL niYuan(LL a, LL b)   //求a对b取模的逆元
    {
        LL x, y;
        exgcd(a, b, x, y);
        return (x + b) % b;
    }
    */
    //费马小定理求逆元
    LL pow(LL a, LL n, LL p) //快速幂 a^n % p
    {
        LL ans = 1;
        while (n)
        {
            if (n & 1)
                ans = ans * a % p;
            a = a * a % p;
            n >>= 1;
        }
        return ans;
    }
    LL niYuan(LL a, LL b) //费马小定理求逆元
    {
        return pow(a, b - 2, b);
    }
    LL C(LL a, LL b) //计算C(a, b)
    {
        return Jc[a] * niYuan(Jc[b], mod) % mod * niYuan(Jc[a - b], mod) % mod;
    }

  public:
    int countAnagrams(string s)
    {
        calJc();

        unordered_map<char, LL> count;
        LL cnt = 0;

        LL ans = 1;

        for (char &ch : s)
        {
            if (ch == ' ')
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    ans = (ans * C(cnt, count[c])) % mod;
                    cnt -= count[c];
                };

                count.clear();
                cnt = 0;
            }
            else
            {
                count[ch]++;
                cnt++;
            };
        };

        for (char c = 'a'; c <= 'z'; c++)
        {
            ans = (ans * C(cnt, count[c])) % mod;
            cnt -= count[c];
        };

        return ans;
    }
};