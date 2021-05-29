#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        else {
            int x = 1;
            for (int i = 0; i < 31; i++) {
                if (n == x) return true;
                else x <<= 1;    
            }
        }
        return false;
    }
};