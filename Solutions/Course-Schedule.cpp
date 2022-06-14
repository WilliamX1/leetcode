class Solution
{
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, int> counts;
        for (int i = 0; i < numCourses; ++i)
            counts[i] = 0;
        for (const vector<int> &pre : prerequisites)
        {
            int a = pre[0], b = pre[1];
            counts[a]++;
        };
        unordered_map<int, vector<int>> next;
        for (const vector<int> &pre : prerequisites)
        {
            int a = pre[0], b = pre[1];
            next[b].push_back(a);
        };
        while (numCourses > 0)
        {
            bool flag = false;
            for (auto iter = counts.begin(); iter != counts.end(); ++iter)
            {
                if (iter->second == 0)
                {
                    for (const int &n : next[iter->first])
                        counts[n]--;
                    numCourses--;
                    counts.erase(iter);
                    flag = true;
                    break;
                };
            };
            if (!flag)
                return false;
        };
        return true;
    }
};