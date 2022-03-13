class Solution {
public:
    int coopDevelop(vector<vector<int>>& skills) {
        int n = skills.size();
        for (vector<int>& skill : skills)
            sort(skill.begin(), skill.end(), less<int>());
        sort(skills.begin(), skills.end(), [](const vector<int>& a, const vector<int>& b) {
            return a.size() < b.size();
        });
        unordered_map<string, int64_t> m;
        int64_t tot = (int64_t) n * ((int64_t) n - 1) / 2, mod = 1e9 + 7;

        for (vector<int>& skill : skills) {
            if (skill.size() == 1) {
                string str1 = to_string(skill[0]);
                tot -= m[str1];

                m[str1]++;
            } else if (skill.size() == 2) {
                string str1 = to_string(skill[0]), str2 = to_string(skill[1]);
                tot -= m[str1];
                tot -= m[str2];
                tot -= m[str1 + "&" + str2];
                
                m[str1 + "&" + str2]++;
            } else if (skill.size() == 3) {
                string str1 = to_string(skill[0]), str2 = to_string(skill[1]), str3 = to_string(skill[2]);
                tot -= m[str1];
                tot -= m[str2];
                tot -= m[str3];
                tot -= m[str1 + "&" + str2];
                tot -= m[str1 + "&" + str3];
                tot -= m[str2 + "&" + str3];
                tot -= m[str1 + "&" + str2 + "&" + str3];
                
                m[str1 + "&" + str2 + "&" + str3]++;
            } else if (skill.size() == 4) {
                string str1 = to_string(skill[0]), str2 = to_string(skill[1]), str3 = to_string(skill[2]), str4 = to_string(skill[3]);
                tot -= m[str1];
                tot -= m[str2];
                tot -= m[str3];
                tot -= m[str4];
                tot -= m[str1 + "&" + str2];
                tot -= m[str1 + "&" + str3];
                tot -= m[str1 + "&" + str4];
                tot -= m[str2 + "&" + str3];
                tot -= m[str2 + "&" + str4];
                tot -= m[str3 + "&" + str4];
                tot -= m[str1 + "&" + str2 + "&" + str3];
                tot -= m[str1 + "&" + str2 + "&" + str4];
                tot -= m[str1 + "&" + str3 + "&" + str4];
                tot -= m[str2 + "&" + str3 + "&" + str4];
                tot -= m[str1 + "&" + str2 + "&" + str3 + "&" + str4];

                m[str1 + "&" + str2 + "&" + str3 + "&" + str4]++;
            };
        };
        tot %= mod;
        return tot;
    }
};