class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            int len = words[i].size(), tot = words[i].size(), end = i + 1;
            while (end < n && len + words[end].size() + 1 <= maxWidth) {
                len += words[end].size() + 1;
                tot += words[end].size();
                end++;
            };

            string str = words[i];
            if (end == n) { // 最后一行
                for (int j = i + 1; j < end; j++) {
                    str.push_back(' ');
                    str.append(words[j]);
                };
            } else {
                int space_cnt = maxWidth - tot;
                for (int j = i + 1; j < end; j++) {
                    int space = (space_cnt - 1) / (end - j) + 1;
                    str.append(string(space, ' '));
                    str.append(words[j]);
                    space_cnt -= space;
                };
            }
            
            str.append(string(maxWidth - str.size(), ' '));
            ans.push_back(str);

            i = end - 1;
        };
        return ans;
    }
};