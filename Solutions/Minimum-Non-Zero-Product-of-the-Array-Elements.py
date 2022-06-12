typedef long long ll;

class Solution {
    struct matrix
    {
        ll a1, a2, b1, b2;
        matrix(ll a1, ll a2, ll b1, ll b2) : a1(a1), a2(a2), b1(b1), b2(b2) {}
        matrix operator*(const matrix &y)
        {
            matrix ans((a1 * y.a1 + a2 * y.b1) % MOD,
                    (a1 * y.a2 + a2 * y.b2) % MOD,
                    (b1 * y.a1 + b2 * y.b1) % MOD,
                    (b1 * y.a2 + b2 * y.b2) % MOD);
            return ans;
        }
    };

    matrix qpow(matrix a, ll n)
    {
        matrix ans(1, 0, 0, 1); //单位矩阵
        while (n)
        {
            if (n & 1)
                ans = ans * a;
            a = a * a;
            n >>= 1;
        }
        return ans;
    }
public:
    int minNonZeroProduct(int p) {
        // (2 ^ p - 1) * (2 ^ p - 2) ^ (2 ^ (p - 1) - 2)
        int64_t mod = 1e9 + 7;
        int64_t ans = (1 << p) - 1;
        

    }
};