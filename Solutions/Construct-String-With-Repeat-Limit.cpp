#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int N = 26;
        vector<int> v(N, 0);
        for (char ch : s)
            v[ch - 'a']++;

        std::string ans = "";
        for (int i = N - 1; i >= 0; i--)
        {
            while (true)
            {
                int num = min(v[i], repeatLimit);
                if (num == 0)
                    break;

                v[i] -= num;
                ans.append(num, i + 'a');

                if (v[i] > 0)
                {
                    bool flag = false;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (v[j] > 0)
                        {
                            ans.append(1, j + 'a');
                            v[j]--;

                            flag = true;
                            break;
                        };
                    };
                    if (!flag)
                        return ans;
                }
                else
                    break;
            };
        };
        return ans;
    }
};