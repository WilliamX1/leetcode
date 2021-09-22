class Solution {
public:
    double myPow(double x, int n) {
        vector<double> v(31, 0.0);
        vector<int> idxs(31, 0);
        v[0] = x;
        idxs[0] = 1;
        for (int i = 1; i < 31; i++) {
            v[i] = v[i - 1] * v[i - 1];
            idxs[i] = 2 * idxs[i - 1];
        };
        int ptr = 31 - 1;
        double res = 1.0;
        int64_t nn = n; 
        nn = nn > 0 ? nn : -nn;
        
        while (ptr >= 0) {
            if (nn >= idxs[ptr]) {
                nn -= idxs[ptr];
                res *= v[ptr];
            } else ptr--;
        };
        return n > 0 ? res : double(1) / res;
    }
};