#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> ans;
        ans.push_back(first);
        int n = encoded.size();
        for (int i = 0; i < n; i++)
            ans.push_back(encoded[i] ^ ans.back());
        return ans;
    }
};