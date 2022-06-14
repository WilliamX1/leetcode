class Solution
{
  public:
    vector<long long> getDistances(vector<int> &arr)
    {
        // unordered_map<int, vector<int> > index;
        // int n = arr.size();
        // vector<long long> answer(n, 0);

        // for (int i = 0; i < n; i++) {
        //     int num = arr[i];
        //     for (const int& idx : index[num]) {
        //         answer[idx] += (long long) (i - idx);
        //         answer[i] += (long long) (i - idx);
        //     };
        //     index[num].push_back(i);
        // };
        // return answer;
        unordered_map<int, vector<int>> index;
        int n = arr.size();
        for (int i = 0; i < n; ++i)
            index[arr[i]].push_back(i);
        vector<long long> answer(n, 0);

        for (auto iter = index.begin(); iter != index.end(); ++iter)
        {
            vector<int> idxs = iter->second;

            for (int i = 1; i < idxs.size(); ++i)
                answer[idxs[0]] += (long long)(idxs[i] - idxs[0]);

            for (int i = 1; i < idxs.size(); ++i)
                answer[idxs[i]] = answer[idxs[i - 1]] +
                                  (long long)((i - 1) - (idxs.size() - 1 - i)) * (long long)(idxs[i] - idxs[i - 1]);
        }
        return answer;
    }
};