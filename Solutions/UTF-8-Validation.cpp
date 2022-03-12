class Solution {
public:
    bool validUtf8(vector<int>& data) {
        const int n = data.size();
        for (int i = 0; i < n; i++) {
            int tmp = (data[i] & 0xff);
            
            tmp >>= 3;
            if (tmp == 0x1e) {
                if (i + 3 >= n) return false;
                for (int j = i + 1; j <= i + 3; j++) {
                    int tmp1 = ((data[j] & 0xff) >> 6) & 0x3;
                    if (tmp1 != 0x2) return false;
                };
                i = i + 3;
                continue;
            };

            tmp >>= 1;
            if (tmp == 0xe) {
                if (i + 2 >= n) return false;
                for (int j = i + 1; j <= i + 2; j++) {
                    int tmp1 = ((data[j] & 0xff) >> 6) & 0x3;
                    if (tmp1 != 0x2) return false;
                };
                i = i + 2;
                continue;
            };

            tmp >>= 1;
            if (tmp == 0x6) {
                if (i + 1 >= n) return false;
                for (int j = i + 1; j <= i + 1; j++) {
                    int tmp1 = ((data[j] & 0xff) >> 6) & 0x3;
                    if (tmp1 != 0x2) return false; 
                };
                i = i + 1;
                continue;
            };

            tmp >>= 2;
            if (tmp == 0x0) continue;

            return false;
        };
        return true;
    }
};