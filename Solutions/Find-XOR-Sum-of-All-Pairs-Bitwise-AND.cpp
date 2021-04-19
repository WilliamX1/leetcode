#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        const int _size1 = arr1.size(), _size2 = arr2.size();
        bool array1[32], array2[32];
        memset(array1, 0, sizeof(array1));
        memset(array2, 0, sizeof(array2));
        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < _size1; j++)
                array1[i] ^= (arr1[j] >> i) & 1;
            for (int j = 0; j < _size2; j++)
                array2[i] ^= (arr2[j] >> i) & 1;
        };
        int res = 0;
        for (int i = 0; i < 32; i++)
            res |= int(array1[i] & array2[i]) << i;
        return res;
    }
};

int main()
{
    return 0;
}