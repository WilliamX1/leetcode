class Solution
{
  public:
    bool _canReach(const vector<int> &arr, int cur, vector<bool> &havebeen, int n)
    {
        if (cur < 0 || cur >= n || havebeen[cur])
            return false;
        if (arr[cur] == 0)
            return true;
        havebeen[cur] = true;
        return _canReach(arr, cur - arr[cur], havebeen, n) || _canReach(arr, cur + arr[cur], havebeen, n);
    };
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<bool> havebeen(n, false);
        return _canReach(arr, start, havebeen, n);
    }
};