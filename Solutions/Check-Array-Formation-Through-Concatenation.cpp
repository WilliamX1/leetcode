class Solution
{
  public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        int n = arr.size();
        for (const vector<int> &p : pieces)
        {
            for (int i = 0; i < n; i++)
            {
                bool flag = true;
                for (int j = 0; j < p.size(); j++)
                    if (arr[i + j] != p[j])
                    {
                        flag = false;
                        break;
                    };
                if (flag)
                {
                    for (int j = 0; j < p.size(); j++)
                        arr[i + j] = 0;
                    break;
                };
            };
        };
        return accumulate(arr.begin(), arr.end(), 0) == 0;
    }
};