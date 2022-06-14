class Solution
{
  public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> P(m);
        for (int i = 0; i < m; i++)
            P[i] = i + 1;
        vector<int> answer;
        for (const int &q : queries)
        {
            int idx = -1, num = 0;
            for (int i = 0; i < m; i++)
            {
                if (P[i] == q)
                {
                    idx = i;
                    num = P[idx];
                    break;
                };
            };
            answer.push_back(idx);
            P.erase(P.begin() + idx);
            P.insert(P.begin(), num);
        };
        return answer;
    }
};