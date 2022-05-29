class BookMyShow {
public:
    vector<int64_t> counts;
    int n, m, line = 0;
    BookMyShow(int n, int m) {
        this->n = n;
        this->m = m;
        counts = vector<int64_t>(n, m);
    }
    
    vector<int> gather(int k, int maxRow) {
        vector<int> v;
        for (int i = line; i <= maxRow; i++)
            if (counts[i] >= k) {
                v.push_back(i);
                v.push_back(m - counts[i]);
                counts[i] -= k;
                break;
            };
        return v;
    }
    
    bool scatter(int k, int maxRow) {
        int64_t tot = 0;
        for (int i = line; i <= maxRow; i++) 
            tot += counts[i];
        
        // cout << tot << endl;
        if (tot >= (int64_t) k) {
            for (int i = 0; i <= maxRow; i++) {
                if (counts[i] < k) {
                    k -= counts[i];
                    counts[i] = 0;
                } else {
                    counts[i] -= k;
                    line = max(line, i);
                    if (counts[i] == 0) 
                        line++;
                    break;
                };
            };
            return true;
        } else return false;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */