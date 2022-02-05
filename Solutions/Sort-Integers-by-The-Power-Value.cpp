class Solution {
public:
    unordered_map<int, int> m;
    int compute(int x) {
        if (m.find(x) != m.end()) return m[x];
 
        if(x & 1) m[x] = compute(3 * x + 1) + 1;
        else m[x] = compute(x / 2) + 1;

        return m[x];
    };
    int getKth(int lo, int hi, int k) {
        m[1] = 0;
        
        vector< vector<int> > v;
        for (int i = lo; i <= hi; i++) {
            m[i] = compute(i);
            v.push_back({m[i], i});
        };
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        return v[k - 1][1];
    }
};