class Solution
{
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

        int n = people.size();
        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++)
        {
            int spaces = people[i][1];
            for (int j = 0; j < n; j++)
            {
                if (ans[j].empty())
                {
                    if (spaces == 0)
                    {
                        ans[j] = people[i]);
                        break;
                    };
                    --spaces;
                };
            };
        };
        return ans;
    }
};