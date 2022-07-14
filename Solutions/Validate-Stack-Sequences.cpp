class Solution
{
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> p;
        int pop_idx = 0, size = popped.size();
        for (int i = 0; i < size; i++)
        {
            p.push(pushed[i]);
            while (!p.empty() && p.top() == popped[pop_idx])
            {
                p.pop();
                pop_idx++;
            };
        };
        return p.empty();
    }
};