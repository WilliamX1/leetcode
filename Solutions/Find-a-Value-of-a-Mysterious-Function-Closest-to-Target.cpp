class Solution
{
  public:
    int closestToTarget(vector<int> &arr, int target)
    {
        set<int> s;
        s.insert(arr[0]);
        int ans = abs(arr[0] - target);
        for (int i = 1; i < arr.size(); i++)
        {
            set<int> ss;
            ss.insert(arr[i]);
            for (const int &ele : s)
                ss.insert(ele & arr[i]);
            s = ss;

            for (const int &ele : s)
                ans = min(ans, abs(ele - target));
        };
        return ans;
    }
};