class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int push_idx = 0, pop_idx = 0, len = pushed.size();
        while (push_idx < len) {
            s.push(pushed[push_idx++]);
            while (!s.empty() && s.top() == popped[pop_idx]) {
                s.pop();
                pop_idx++;
            };
        };
        return s.empty();
    }
};