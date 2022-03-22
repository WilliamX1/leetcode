class Solution {
public:
    bool OK(string s, int l, int r) {
        while (l < r)
            if (s[l] == s[r]) {
                l++;
                r--;
            } else return false;
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else return OK(s, left + 1, right) || OK(s, left, right - 1);
        };
        return true;
    }
};