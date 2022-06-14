#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string removeDuplicates(string s)
    {
        stack<char> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (q.empty() || q.top() != s[i])
                q.push(s[i]);
            else
                q.pop();
        };
        vector<char> v;
        while (!q.empty())
        {
            v.push_back(q.top());
            q.pop();
        };
        string ans;
        for (int i = v.size() - 1; i >= 0; i--)
            ans += v[i];
        return ans;
    }
};