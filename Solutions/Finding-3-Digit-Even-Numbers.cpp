class Solution
{
  public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        set<int> s;
        for (int i = 0; i < digits.size(); i++)
            for (int j = 0; j < digits.size(); j++)
                for (int k = 0; k < digits.size(); k++)
                    if (i != j && i != k && j != k && digits[i] != 0 && (digits[k] & 1) == 0)
                        s.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
        vector<int> ans;
        for (auto ele : s)
            ans.push_back(ele);
        sort(ans.begin(), ans.end(), less<int>());
        return ans;
    }
};