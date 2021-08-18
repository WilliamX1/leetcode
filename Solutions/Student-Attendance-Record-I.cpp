class Solution {
public:
    bool checkRecord(string s) {
        int totA = 0, totL = 0;
        for (auto ch : s)
        {
            totA += ch == 'A';
            totL += ch == 'L' ? 1 : -totL;
            if (totA >= 2 || totL >= 3) return false;
        };
        return true;
    }
};