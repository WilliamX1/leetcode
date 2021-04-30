#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*分组异或，先算出x = a ^ b，再按照x某位分成两组*/
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
            x ^= nums[i];
        vector<int> A, B;
        //寻找用于分组的位，需要该位是1
        int idx = 0;
        while (((x >> idx) & 1) != 1) idx++;
        for (int i = 0; i < nums.size(); i++)
        {
            if (((nums[i] >> idx) & 1) == 0) A.push_back(nums[i]);
            else B.push_back(nums[i]);
        };
        int resA = 0, resB = 0;
        for (int i = 0; i < A.size(); i++) resA ^= A[i];
        for (int i = 0; i < B.size(); i++) resB ^= B[i];
        return {resA, resB};
    }
};

int main()
{
    Solution S;
    vector<int> v = {1,2,1,3,2,5};
    S.singleNumber(v);
    return 0;
}