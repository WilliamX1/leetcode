class Solution
{
  public:
    string removeDigit(string number, char digit)
    {
        vector<string> v;
        int n = number.size();
        for (int i = 0; i < n; i++)
        {
            if (number[i] == digit)
            {
                v.push_back(number.substr(0, i) + number.substr(i + 1));
            };
        };
        sort(v.begin(), v.end(), greater<string>());
        return v[0];
    }
};