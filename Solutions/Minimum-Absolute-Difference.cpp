class Solution
{
  public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int x = 0x7fffffff;
        for (int i = 0; i < n - 1; i++)
            x = min(x, arr[i + 1] - arr[i]);

        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
            if (arr[i + 1] - arr[i] == x)
                ans.push_back({arr[i], arr[i + 1]});
        sort(ans.begin(), ans.end(), [](const vector<int> &A, const vector<int> &B) { return A[0] < B[0]; });
        return ans;
    }
};