class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> v;
        int _max = pow(10, n);
        for (int i = 1; i < _max; i++)
            v.push_back(i);
        return v;
    }
};