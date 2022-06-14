#include <vector>

using namespace std;

class Solution
{
  public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> v;
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            if (!arr[i])
                v.push_back(arr[i]);
            v.push_back(arr[i]);
        };
        std::copy(v.begin(), v.begin() + len, arr.begin());
        return;
    }
};