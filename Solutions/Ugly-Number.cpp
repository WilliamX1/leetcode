#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        /*暴力除法*/
        if (n < 1) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};

int main()
{
    return 0;
}