class Solution {
public:
    struct node {
        int index; 
        int score;
        node() {};
        node(int index, int score) : index(index), score(score) {};
        bool operator>(const node& other) const {
            return score < other.score;
        };
    };
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        priority_queue<node, vector<node>, greater<node> > pque;
        pque.push(node(0, nums[0]));
        for (int i = 1; i < n; i++) {
            while (!pque.empty()) {
                node top = pque.top();
                if (i - top.index > k) pque.pop();
                else {
                    node new_node = node(i, top.score + nums[i]);
                    pque.push(new_node);
                    break;
                };
            };
        };
        while (!pque.empty() && pque.top().index < n - 1) pque.pop();
        return pque.top().score;
    }
};