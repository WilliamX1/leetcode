#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
using LL = long long;

class Solution
{
  public:
    vector<int> prime_actorization(int k)
    {
        vector<int> ans;
        for (int i = 1; i <= k; i++)
        {
            if (k % i == 0)
            {
                ans.push_back(i);
            };
        };
        return ans;
    };
    int gcd(int a, int b)
    {
        int tmp;
        while (a != 0)
        {
            tmp = a;
            a = b % a;
            b = tmp;
        };
        return b;
    };
    long long countPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        vector<int> primes = prime_actorization(k);
        LL ans = 0;
        for (int v : nums)
        {
            ans += cnt[k / gcd(k, v)];
            for (int u : primes)
            {
                if (v % u == 0)
                {
                    cnt[u]++;
                };
            };
        };
        return ans;
    }
};