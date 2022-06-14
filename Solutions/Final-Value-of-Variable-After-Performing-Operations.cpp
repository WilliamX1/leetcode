class Solution
{
  public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int ans = 0;
        for (int i = 0; i < operations.size(); i++)
            if (operations[i].front() == '+' || operations[i].back() == '+')
                ans++;
            else
                ans--;
        return ans;
    }
};