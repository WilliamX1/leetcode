class MinStack
{
  public:
    stack<int> stk;
    unordered_map<int, int> umap;
    priority_queue<int, vector<int>, greater<int>> pque;
    MinStack()
    {
    }

    void push(int val)
    {
        stk.push(val);
        umap[val]++;
        pque.push(val);
    }

    void pop()
    {
        umap[stk.top()]--;
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        while (!umap[pque.top()])
            pque.pop();
        return pque.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */