class Solution
{
  public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size(), tot_back = 0, tot_front = 0;
        vector<int> v(n, 0);
        v[0] = boxes[0] == '1';
        for (int i = 1; i < n; i++)
        {
            v[i] = v[i - 1] + (boxes[i] == '1');
            tot_back += i * (boxes[i] == '1');
        };

        vector<int> ans(n, 0);
        ans[0] = tot_back;
        for (int i = 1; i < n; i++)
        {
            tot_back -= v[n - 1] - v[i - 1];
            tot_front += v[i - 1];
            ans[i] = tot_back + tot_front;
        };
        return ans;
    }
};