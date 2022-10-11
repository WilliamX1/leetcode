class Solution
{
  public:
    bool equalFrequency(string word)
    {
        unordered_map<char, int> count;
        for (char &ch : word)
            count[ch]++;
        vector<int> v;
        for (char ch = 'a'; ch <= 'z'; ch++)
            if (count[ch])
                v.push_back(count[ch]);
        sort(v.begin(), v.end());

        int n = v.size();
        return n == 1 || v[0] == 1 && v[1] == v[n - 1] || v[0] == v[n - 2] && v[n - 1] - v[n - 2] == 1;
    }
};