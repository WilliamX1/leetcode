class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0, n = nums.size() - 1;
        for (int i = 0; i < 32; i++) {
            int x = 0, y = 0;
            for (int j = 1; j <= n; j++) 
                if ((j >> i) & 1) x++;
            for (int j = 0; j <= n; j++)
                if ((nums[j] >> i) & 1) y++;
            if (y > x) ans |= (1 << i);
        };
        return ans;
    }
};