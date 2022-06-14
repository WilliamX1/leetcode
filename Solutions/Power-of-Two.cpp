#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && int(pow(2, 30)) % n == 0;
    }
};