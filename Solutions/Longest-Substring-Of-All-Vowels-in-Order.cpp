class Solution
{
  public:
    int longestBeautifulSubstring(string word)
    {
        word.push_back('a');

        int ans = 0, n = word.size(), i = 0;
        deque<pair<int, int>> stk;

        unordered_map<char, int> priority;
        for (char ch = 'a'; ch <= 'z'; ch++)
            priority[ch] = 0;
        priority['a'] = 1;
        priority['e'] = 2;
        priority['i'] = 3;
        priority['o'] = 4;
        priority['u'] = 5;

        bool flag = false;
        while (i < n)
        {
            const char &ch = word[i];
            // cout << "i: " << i << " stksize: " << stk.size() << endl;
            if (stk.empty())
            {
                if (priority[ch] <= 1)
                    stk.emplace_back(priority[ch], i);
            }
            else
            {
                if (flag)
                {
                    if (priority[ch] == 0)
                        stk.emplace_back(priority[ch], i);
                    else
                    {
                        // cout << "here" << endl;
                        ans = max(ans, stk.back().second - stk.front().second + 1);
                        flag = false;
                        stk.clear();
                        i--;
                    };
                }
                else
                {
                    if (stk.back().first == 5)
                    {
                        if (priority[ch] == 5)
                            stk.emplace_back(priority[ch], i);
                        else if (priority[ch] == 0)
                        {
                            flag = true;
                            stk.emplace_back(priority[ch], i);
                        }
                        else
                        {
                            ans = max(ans, stk.back().second - stk.front().second + 1);
                            stk.clear();
                            i--;
                        };
                    }
                    else if (stk.back().first == priority[ch] || stk.back().first + 1 == priority[ch])
                        stk.emplace_back(priority[ch], i);
                    else
                    {
                        stk.clear();
                        i--;
                    };
                };
            };
            i++;
        };
        return ans;
    }
};