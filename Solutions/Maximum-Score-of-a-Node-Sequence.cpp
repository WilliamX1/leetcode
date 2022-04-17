class Solution {
public:
    struct node {
        int another_edge;
        int weight;
        node () {};
        node (int another_edge, int weight) : another_edge(another_edge), weight(weight) {};
        bool operator>(const node& other) const {
            return weight > other.weight;
        }
    };
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<node>> top3nodes(n);
        for (const vector<int>& edge : edges) {
            int a = edge[0], b = edge[1];

            top3nodes[a].push_back(node(b, scores[b]));
            sort(top3nodes[a].begin(), top3nodes[a].end(), greater<node>());
            while (top3nodes[a].size() > 3) top3nodes[a].pop_back();
            
            top3nodes[b].push_back(node(a, scores[a]));
            sort(top3nodes[b].begin(), top3nodes[b].end(), greater<node>());
            while (top3nodes[b].size() > 3) top3nodes[b].pop_back();
        };

        int ans = -1;
        for (const vector<int>& edge : edges) {
            int a = edge[0], b = edge[1];

            for (const node& a_another : top3nodes[a])
                if (b != a_another.another_edge)
                    for (const node& b_another : top3nodes[b])
                        if (a != b_another.another_edge && a_another.another_edge != b_another.another_edge) {
                            // cout << a << ' ' << b << ' ' << a_another.another_edge << ' ' << b_another.another_edge << endl;
                            ans = max(ans, scores[a] + scores[b] + scores[a_another.another_edge] + scores[b_another.another_edge]);
                        };
        };
        return ans;
    }
};