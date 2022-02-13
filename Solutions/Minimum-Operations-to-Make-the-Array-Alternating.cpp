#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> odd, even;
        for (int i = 0; i < len; i++) {
            if (i & 1) odd[nums[i]]++;
            else even[nums[i]]++;
        };

        vector< vector<int> > odd_v, even_v;
        for (unordered_map<int, int>::iterator iter = odd.begin(); iter != odd.end(); iter++) {
            vector<int> v;
            v.push_back(iter->first);
            v.push_back(iter->second);
            odd_v.push_back(v);
        };
        for (unordered_map<int, int>::iterator iter = even.begin(); iter != even.end(); iter++) {
                        vector<int> v;
            v.push_back(iter->first);
            v.push_back(iter->second);
            even_v.push_back(v);
        }
        sort(odd_v.begin(), odd_v.end(), [](const vector<int>& A, const vector<int>& B) {
            return A[1] > B[1];
        });
        sort(even_v.begin(), even_v.end(), [](const vector<int>& A, const vector<int>& B) {
            return A[1] > B[1];
        });

        int tot_max = 0;

        for (int i = 0; i < odd_v.size(); i++)
        {
            tot_max = max(tot_max, odd_v[i][1]);
            for (int j = 0; j < even_v.size(); j++)
                if (odd_v[i][0] != even_v[j][0]) {
                    tot_max = max(tot_max, odd_v[i][1] + even_v[j][1]);
                    break;
                };
        };
        for (int i = 0; i < even_v.size(); i++)
        {
            tot_max = max(tot_max, even_v[i][1]);
            for (int j = 0; j < odd_v.size(); j++)
                if (even_v[i][0] != odd_v[j][0]) {
                    tot_max = max(tot_max, even_v[i][1] + odd_v[j][1]);
                    break;
                };
        };
        return len - tot_max;
    }
};