class Solution {
public:
    int compress(vector<char>& chars) {
        char cur = chars[0];
        int len = chars.size(), cur_len = 0, idx = 0, new_len = len;
        while (idx < len)
        {
            while (idx < len && chars[idx] == cur) {
                idx++;
                cur_len++;
            };
            string str = cur_len > 1 ? to_string(cur_len);
            int i = 0, size = str.size();
            for (int i = 0; i < size; i++)
                chars[idx - cur_len + i + 1] = str[i];
            
            new_len = idx - cur_len + size + 1;
            if (idx < len) {
                cur = chars[idx];
                cur_len = 0;
            };
        };
        return new_len;
    }
};