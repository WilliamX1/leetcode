class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int64_t n = nums.size(), tot = 0;
        vector< vector<int> > M_vec(n, vector<int>(n, -1e9)), m_vec(n, vector<int>(n, 1e9));
        
        for (int i = 0; i < n; i++)
            M_vec[i][i] = m_vec[i][i] = nums[i];

        for (int step = 1; step < n; step++)
            for (int i = 0; i + step < n; i++) {
                M_vec[i][i + step] = max(M_vec[i + 1][i + step], nums[i]);
                m_vec[i][i + step] = min(m_vec[i + 1][i + step], nums[i]);
            };
        
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                tot += (long long) M_vec[i][j] - m_vec[i][j];
        
        return tot;
    }
};