class Solution
{
  public:
    struct node
    {
        string str;
        int index;
        node(){};
        node(string s, int i) : str(s), index(i){};
    };
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> answer;
        for (const vector<int> q : queries)
        {
            int k = q[0], trim = q[1];
            vector<node> v;
            for (int i = 0; i < nums.size(); i++)
                v.push_back(node(nums[i].substr(nums[i].size() - trim), i));
            sort(v.begin(), v.end(),
                 [](const node &a, const node &b) { return a.str == b.str ? a.index < b.index : a.str < b.str; });
            answer.push_back(v[k - 1].index);
        };
        return answer;
    }
};