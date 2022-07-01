class Solution
{
  public:
    unordered_map<int, int> remove;
    bool isSubstr(const string &str, const string &substr)
    {
        int n1 = str.size(), n2 = substr.size();
        if (n1 < n2)
            return false;

        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2)
        {
            if (str[i1] == substr[i2])
            {
                i1++;
                i2++;
            }
            else
                i1++;
        };
        // cout << "str: " << str << " substr: " << substr << " isSubstr: " << (i2 >= n2) << endl;
        return i2 >= n2;
    };
    string getStr(const string &s, int end)
    {
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (!remove.count(i) || remove[i] >= end)
                ans.push_back(s[i]);
        };
        return ans;
    };
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        for (int i = 0; i < removable.size(); i++)
            remove[removable[i]] = i;

        int left = 0, right = removable.size();
        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (isSubstr(getStr(s, mid), p))
                left = mid + 1;
            else
                right = mid - 1;
        };
        return right;
    }
};