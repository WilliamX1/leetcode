class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        sort(ideas.begin(), ideas.end());
        vector<vector<long long>> cnts(26, vector<long long>(26, 0));
        
        unordered_map<string, unordered_set<char>> prefix;
        for (const string& i : ideas)
            prefix[i.substr(1)].insert(i[0]);
        
        long long ans = 0;
        vector<long long> presum(26, 0);
        for (const string& i : ideas) {
            for (char j = 'a'; j <= 'z'; j++) {
                if (!prefix[i.substr(1)].count(j) && presum[j - 'a']) {
                    ans += presum[j - 'a'];
                    cnts[j - 'a'][i[0] - 'a']++;
                };
            };
            // cout << ans << ' ' ;
            presum[i[0] - 'a']++;
        };
        // cout << endl;
        for (const string& i : ideas) {
            for (const char& ch : prefix[i.substr(1)]) {
                // cout << "i[0]: " << i[0] << " ch " <<  ch << " cnts: " << cnts[i[0] - 'a'][ch - 'a'] << endl;
                ans -= cnts[i[0] - 'a'][ch - 'a'];
            };
            // cout << ans << endl;
        };
        ans *= 2;
        return ans;
    }
};