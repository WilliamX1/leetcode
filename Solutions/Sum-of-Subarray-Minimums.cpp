/* 二分法，将 arr 分成两个子数组，然后分别求解他们的 min(b) 的总和再相加，中间每次处理都需要 NlogN 的时间，*/
/* 时间复杂度：O(NlogNlogN)，空间复杂度 O(NlogN) */
/* 测试用例：arr = {3,1,2,4} ans = 17 */

#include <vector>
#include <algorithm>

using LL = long long;
using namespace std;

class Solution{
public:
  const int mod = (int)1e9 + 7;
  int _sumSubarrayMins(vector<int>& arr, int left, int right, int dir, vector<int>& m) {
    if (left == right) {
      m.push_back(arr[left]);
      return arr[left];
    };

    int mid = (left + right) >> 1;
    vector<int> m1, m2;
    int tot = ((LL)_sumSubarrayMins(arr, left, mid, 1, m1) + (LL)_sumSubarrayMins(arr, mid + 1, right, 0, m2)) % mod;
    int len1 = m1.size(), len2 = m2.size();
    vector<int> prefix1(len1 + 1, 0), prefix2(len2 + 1, 0);
    for (int i = 0; i < len1; i++) prefix1[i + 1] = prefix1[i] + m1[i];
    for (int i = 0; i < len2; i++) prefix2[i + 1] = prefix2[i] + m2[i];
    for (int i = 0; i < len1; i++) {
        int idx = upper_bound(m2.begin(), m2.end(), m1[i]) - m2.begin();
        tot = ((LL)tot + (LL)(len2 - idx) * (LL)m1[i] + (LL)prefix2[idx]) % mod;
    };
    if (dir == 0) /* 原数组右侧 */ {
      m.push_back(arr[left]);
      for (int i = left + 1; i <= right; i++)
        m.push_back(min(m.back(), arr[i]));
    } else {
      m.push_back(arr[right]);
      for (int i = right - 1; i >= left; i--)
        m.push_back(min(m.back(), arr[i]));
    };
    sort(m.begin(), m.end());
    return tot;
  };
  int sumSubarrayMins(vector<int>& arr) {
    vector<int> m;
    return _sumSubarrayMins(arr, 0, arr.size() - 1, 0, m);  
  };
};