class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string substr = word;
        while (sequence.find(substr) != string::npos) {
            substr += word;
            ans++;
        };
        return ans;
    }
};