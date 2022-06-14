class Solution
{
  public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        unordered_map<int, int> counts;
        unordered_map<int, unordered_map<int, int>> edge_cnts;
        for (vector<int> &e : edges)
        {
            if (e[0] > e[1])
                swap(e[0], e[1]);
            counts[e[0]]++;
            counts[e[1]]++;
            edge_cnts[e[0]][e[1]]++;
        };

        vector<int> v;
        for (auto iter : counts)
            v.push_back(iter.second);
        sort(v.begin(), v.end());

        vector<int> answer(queries.size());
        unordered_map<int, int> ans;
        for (int k = 0; k < queries.size(); k++)
        {
            const int cnt = queries[k];
            if (ans.count(cnt))
            {
                answer[k] = ans[cnt];
                continue;
            };

            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] > cnt)
                    answer[k] += 2 * (n - v.size());
                int j = v.size() - (upper_bound(v.begin(), v.end(), cnt - v[i]) - v.begin());
                answer[k] += j - (2 * v[i] > cnt);
            };
            answer[k] >>= 1;

            for (auto iter : edge_cnts)
            {
                int l = iter.first;
                for (auto iter1 : iter.second)
                {
                    int r = iter1.first;
                    if (counts[l] + counts[r] > cnt && counts[l] + counts[r] - iter1.second <= cnt)
                        answer[k]--;
                };
            };
            ans[cnt] = answer[k];
        };

        return answer;
    }
};