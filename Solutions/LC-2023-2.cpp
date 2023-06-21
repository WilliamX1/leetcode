class Solution {
public:
    int adventureCamp(vector<string>& expeditions) {
        int n = expeditions.size();

        unordered_set<string> se;
        se.insert("");
        int M = 0, index = -1;
        for (int i = 0; i < n; i++) {
            string s;
            int m = 0;
            for (int j = 0; j < expeditions[i].size(); j++) {
                if (expeditions[i][j] == '-') {
                    if (!se.count(s)) {
                        se.insert(s);
                        m++;
                    };
                    j++;
                    s.clear();
                } else {
                    s.push_back(expeditions[i][j]);
                };
            };
            if (!se.count(s)) {
                se.insert(s);
                m++;
            };
            // cout << m << ' ';
            if ((m > M) && i) {
                M = m;
                index = i;
            };
        };
        // cout << endl;
        return index;
    };
};