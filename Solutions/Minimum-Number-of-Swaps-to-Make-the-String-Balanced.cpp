class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = s.size() - 1, ans = 0, left_num = 0, right_num = 0;
        while (left < right)
        {
            while (left < right) {
                if (left_num == 0 && s[left] == '[') left_num++, left++;
                else if (left_num != 0) {
                    left_num += s[left] == '[' ? 1 : -1;
                    left++;
                } else break;
            };
            while (left < right) {
                if (right_num == 0 && s[right] == ']') right_num++, right--;
                else if (right_num != 0) {
                    right_num += s[right] == ']' ? 1 : -1;
                    right--;
                } else break;
            };
            if (left < right) {
                swap(s[left], s[right]);
                ans++;
            };
        };
        return ans;
    }
};