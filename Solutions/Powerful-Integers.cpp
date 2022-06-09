class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> vx, vy;
        vx.push_back(1);
        vy.push_back(1);

        if (x > 1) {
            int xx = x;
            while (xx < bound) {
                vx.push_back(xx);
                xx *= x;
            };
        };
        if (y > 1) {
            int yy = y;
            while (yy < bound) {
                vy.push_back(yy);
                yy *= y;
            };
        };

        set<int> s;
        for (int xx : vx)
            for (int yy : vy)
                if (xx + yy <= bound) s.insert(xx + yy);
                else break;
        vector<int> ans;
        for (auto xx : s) ans.push_back(xx);
        return ans;
    }
};