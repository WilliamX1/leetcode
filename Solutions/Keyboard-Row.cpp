class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m;
        vector<char> v1 = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
        vector<char> v2 = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
        vector<char> v3 = {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

        for (unsigned int i = 0; i < v1.size(); i++)
            m[v1[i]] = m[v1[i] - 'A' + 'a'] = 1;

        for (unsigned int i = 0; i < v2.size(); i++)
            m[v2[i]] = m[v2[i] - 'A' + 'a'] = 2;

        for (unsigned int i = 0; i < v3.size(); i++)
            m[v3[i]] = m[v3[i] - 'A' + 'a'] = 3;
        
        vector<string> v;
        for (auto& str : words) {
            int u = m[str[0]];
            bool flag = true;
            for (unsigned int i = 1; i < str.size(); i++)
                if (m[str[i]] != u) {
                    flag = false;
                    break;
                };
            if (flag) v.push_back(str);
        };
        return v;
    }
};