class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numstr = to_string(num);
        int n = numstr.length(), count = 0;
        for (int i = 0; i <= n - k; i++) {
            string substr = numstr.substr(i, k);
            while (!substr.empty() && substr[0] == '0') substr.erase(substr.begin());
            if (!substr.empty())
                count += (num % stol(substr)) == 0;
        };
        return count;
    }
};