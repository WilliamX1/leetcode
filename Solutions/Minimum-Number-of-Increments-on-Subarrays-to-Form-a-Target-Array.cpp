#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int cnt = 0;
    unordered_map<int, vector<int>> m;

    void two_point(const vector<int> &target, const int start, const int end, const int last)
    {
        if (start >= end)
            return;
        cout << "start " << start << " end " << end << endl;
        int t = *min_element(target.begin() + start, target.begin() + end);
        vector<int> v = m[t];

        int s = lower_bound(v.begin(), v.end(), start) - v.begin();
        if (s >= 0 && v[s] >= start)
        {
            two_point(target, start, v[s], t);
        }

        while (s < v.size() && v[s] < end)
        {
            int b = s + 1 < v.size() && v[s + 1] < end ? v[s + 1] : end;
            two_point(target, v[s] + 1, b, t);
            s++;
        };
        cnt += t - last;
        return;
    };
    int minNumberOperations(vector<int> &target)
    {
        // int len = target.size();
        // for (int i = 0; i < len; i++) {
        //     vector<int> v;
        //     if (m.find(target[i]) != m.end()) v = m[target[i]];
        //     v.push_back(i);
        //     m[target[i]] = v;
        // };

        // two_point(target, 0, len, 0);
        // return cnt;
        int n = target.size();
        int ans = target[0];
        for (int i = 1; i < n; i++)
        {
            ans += max(target[i] - target[i - 1], 0);
        };
        return ans;
    }
};