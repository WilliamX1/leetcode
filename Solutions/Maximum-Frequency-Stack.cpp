class FreqStack
{
    struct node
    {
        int val;
        int cnt;
        int pos;
        node(){};
        node(int v, int c = 0, int p = 0) : val(v), cnt(c), pos(p){};
    };

    struct cmp
    {
        bool operator()(const node &a, const node &b) const
        {
            return a.cnt == b.cnt ? a.pos > b.pos : a.cnt > b.cnt;
        };
    };

    unordered_map<int, node> val2node;
    unordered_map<int, deque<int>> poss;

    map<node, int, cmp> pque;
    int index = 0;

  public:
    FreqStack()
    {
    }

    void push(int val)
    {
        // cout << "push: " << val << endl;
        auto iter = val2node.find(val);
        struct node nn;
        if (iter == val2node.end())
            nn = node(val, 1, index++);
        else
        {
            nn = iter->second;

            pque.erase(pque.find(nn));
            nn.cnt++;
            nn.pos = index++;
        };
        poss[val].push_back(nn.pos);
        val2node[val] = nn;
        pque[nn] = nn.val;
    }

    int pop()
    {
        // cout << "pop: ";
        auto iter = pque.begin();
        struct node nn = iter->first;
        pque.erase(iter);

        nn.cnt--;
        poss[nn.val].pop_back();

        if (nn.cnt)
        {
            nn.pos = poss[nn.val].back();

            val2node[nn.val] = nn;
            pque[nn] = nn.val;
        }
        else
            val2node.erase(val2node.find(nn.val));

        // cout << nn.val << endl;
        return nn.val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */