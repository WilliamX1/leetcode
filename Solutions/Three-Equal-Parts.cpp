class Solution
{
  public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int tailzeros = 0, n = arr.size();
        for (int i = n - 1; i >= 0 && !arr[i]; i--)
            tailzeros++;
        int ones = accumulate(arr.begin(), arr.end(), 0);
        if (ones % 3)
            return {-1, -1};
        else if (!ones)
            return {0, 2};
        else
            ones /= 3;

        int tmpones, index = 0;
        string str, laststr;
        vector<int> ans;
        while (index < n)
        {
            tmpones = 0;
            while (index < n && !arr[index])
                index++;
            while (index < n && tmpones < ones)
            {
                str.push_back(arr[index] + '0');
                tmpones += arr[index++];
            };
            for (int i = 0; i < tailzeros; i++)
                if (index >= n || arr[index])
                    return {-1, -1};
                else
                    str.push_back(arr[index++] + '0');
            ans.push_back(index - 1);
            // cout << "str: " << str << " laststr: " << laststr << endl;
            if (!laststr.empty() && str != laststr)
                return {-1, -1};
            else
            {
                laststr = str;
                str.clear();
            };
        };
        return {ans[0], ans[1] + 1};
    }
};