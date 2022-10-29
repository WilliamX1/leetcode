class Solution
{
  public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int ans = 0;
        for (const vector<string> &item : items)
        {
            ans += ruleKey == "type" && ruleValue == item[0];
            ans += ruleKey == "color" && ruleValue == item[1];
            ans += ruleKey == "name" && ruleValue == item[2];
        };
        return ans;
    }
};