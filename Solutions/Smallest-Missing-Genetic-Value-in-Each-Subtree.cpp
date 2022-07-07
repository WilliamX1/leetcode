class Solution
{
  public:
    unordered_set<int> dfs(const vector<vector<int>> &sons, const vector<int> &nums, vector<int> &answer, const int &n,
                           const int &root)
    {
        unordered_set<int> s;

        int left = 1;
        for (const int &son : sons[root])
        {
            unordered_set<int> tmp = std::move(dfs(sons, nums, answer, n, son));
            if (tmp.size() > s.size())
                swap(s, tmp);
            for (const int &num : tmp)
                s.insert(num);

            left = max(left, answer[son]);
        };

        s.insert(nums[root]);

        while (s.count(left))
            left++;
        answer[root] = left;

        return s;
    };

    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums)
    {
        int n = parents.size();
        vector<int> answer(n);
        vector<vector<int>> sons(n);
        for (int i = 0; i < parents.size(); i++)
            if (parents[i] != -1)
                sons[parents[i]].push_back(i);
        dfs(sons, nums, answer, n, 0);
        return answer;
    }
};