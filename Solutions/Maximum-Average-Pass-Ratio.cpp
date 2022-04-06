class Solution {
public:
    struct node {
        int pass;
        int total;
        node () {};
        node (int pass, int total) : pass(pass), total(total) {};
        bool operator<(const node& other) const {
            return double (pass + 1) / double (total + 1) - (double) pass / (double) total < double (other.pass + 1) / double (other.total + 1) - (double) other.pass / (double) other.total;
        };
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<node, vector<node>, less<node>> pque;
        for (const vector<int>& cls : classes) {
            int pass = cls[0], total = cls[1];
            pque.push(node(pass, total));
        };
        while (extraStudents-- > 0) {
            node t = pque.top();
            pque.pop();

            t.pass++;
            t.total++;

            pque.push(t);
        };
        double ans = 0;
        while (!pque.empty()) {
            int pass = pque.top().pass, total = pque.top().total;
            pque.pop();
            ans += double(pass) / double(total);
        }
        ans /= (double) classes.size();
        return ans;
    }
};