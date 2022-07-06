class Solution
{
  public:
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.size();
        string str1, str2, str3, str4;
        vector<string> ans;
        std::regex reg("([0-9])|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5])");
        for (int i = 1; i <= 3; i++)
        {
            str1.clear();
            for (int tmp = 1; tmp <= i; tmp++)
                str1.push_back(s[-1 + tmp]);
            // cout << str1 << ' ';
            if (!std::regex_match(str1, reg))
                continue;

            for (int j = 1; j <= 3; j++)
            {
                str2.clear();
                for (int tmp = 1; tmp <= j; tmp++)
                    str2.push_back(s[-1 + i + tmp]);
                // cout << str2 << ' ';
                if (!std::regex_match(str2, reg))
                    continue;

                for (int k = 1; k <= 3; k++)
                {
                    str3.clear();
                    for (int tmp = 1; tmp <= k; tmp++)
                        str3.push_back(s[-1 + i + j + tmp]);
                    // cout << str3 << ' ';
                    if (!std::regex_match(str3, reg))
                        continue;

                    for (int l = 1; l <= 3; l++)
                    {
                        str4.clear();
                        for (int tmp = 1; tmp <= l; tmp++)
                            str4.push_back(s[-1 + i + j + k + tmp]);
                        // cout << str4 << ' ';
                        if (!std::regex_match(str4, reg))
                            continue;

                        if (i + j + k + l == n)
                            ans.push_back(str1 + "." + str2 + "." + str3 + "." + str4);
                    };
                };
            };
        };
        return ans;
    }
};