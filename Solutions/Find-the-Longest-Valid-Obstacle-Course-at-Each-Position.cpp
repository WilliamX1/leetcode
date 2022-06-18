class Solution
{
  public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> v, ans;
        for (int &ob : obstacles)
        {
            if (v.empty() || ob >= v.back())
            {
                v.push_back(ob);
                ans.push_back(v.size());
            }
            else
            {
                int loc = upper_bound(v.begin(), v.end(), ob) - v.begin();
                ans.push_back(loc + 1);
                v[loc] = ob;
            };
        };
        return ans;
    }
};