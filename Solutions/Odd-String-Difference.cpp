class Solution
{
  public:
    string oddString(vector<string> &words)
    {
        int n = words.size();
        vector<vector<char>> nums;
        for (int i = 0; i < 3; i++)
        {
            vector<char> v;
            for (int j = 1; j < words[i].size(); j++)
                v.push_back(words[i][j] - words[i][j - 1]);
            nums.push_back(v);
        };

        vector<char> vv;
        if (nums[0] == nums[1])
            vv = nums[0];
        else if (nums[0] == nums[2])
            vv = nums[0];
        else
            vv = nums[1];

        for (int i = 0; i < n; i++)
        {
            vector<char> v;
            for (int j = 1; j < words[i].size(); j++)
                v.push_back(words[i][j] - words[i][j - 1]);
            if (vv != v)
                return words[i];
        }
        return "";
    }
};