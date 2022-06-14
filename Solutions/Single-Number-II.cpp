#include <memory.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int bits[32], tmp, size = nums.size();
        memset(bits, 0, sizeof(bits));

        for (int i = 0; i < size; i++)
        {
            tmp = nums[i];
            for (int j = 0; j < 32 && tmp; j++)
            {
                bits[j] += tmp & 1;
                tmp >>= 1;
            };
        };
        int res = 0;
        for (int j = 0; j < 32; j++)
            res |= (bits[j] % 3) << j;
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> v = {2, 2, 3, 2};
    printf("%d", S.singleNumber(v));
    return 0;
}