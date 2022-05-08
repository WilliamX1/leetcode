class Solution {
public:
    string largestGoodInteger(string num) {
        for (int i = 9; i >= 0; i--) {
            string sub;
            for (int j = 0; j < 3; j++) {
                sub.push_back(i + '0');
            };
            if (num.find(sub) != string::npos)
                return sub;
        };
        return "";
    }
};