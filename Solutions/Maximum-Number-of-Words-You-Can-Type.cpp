class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> flag(26, 1);
        for (auto ch : brokenLetters) flag[ch - 'a'] = false;

        int ans = 0;
        text = text + ' ';
        while (text != "")
        {
            string word = text.substr(0, text.find_first_of(' '));
            bool f = true;
            for (auto ch : word) 
                if (!flag[ch - 'a'])
                {
                    f = false; 
                    break;
                };

            ans += f;
            text = text.substr(text.find_first_of(' ') + 1);
        };
        return ans;
    }
};