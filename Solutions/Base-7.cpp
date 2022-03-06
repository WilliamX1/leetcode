class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        bool isNeg = num < 0;
        
        num = abs(num);
        while (num > 0) {
            ans.append(to_string(num % 7));
            num /= 7;
        };
        reverse(ans.begin(), ans.end());
        if (isNeg) ans = "-" + ans;
        return ans;
    }
};