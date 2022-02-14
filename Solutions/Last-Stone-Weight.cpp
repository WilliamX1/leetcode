#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int> > q;
        for (auto& stone : stones) q.push(stone);
        while (q.size() > 1) {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            if (x != y) q.push(abs(x - y));
        };
        return q.size() > 0 ? q.top() : 0;
    }
};