class Solution {
public:
    string entityParser(string text) {
        string ans;
        for (int i = 0; i < text.length();) {
            if (text[i] == '&') {
                string substr = "&";
                int next = i + 1;
                while (next < text.length() && text[next] != ';' && text[next] != '&') {
                    substr.push_back(text[next++]);
                };
                if (next < text.length() && text[next] == ';') {
                    i = next + 1;
                    if (substr == "&quot") ans.push_back('\"');
                    else if (substr == "&apos") ans.push_back('\'');
                    else if (substr == "&amp") ans.push_back('&');
                    else if (substr == "&gt") ans.push_back('>');
                    else if (substr == "&lt") ans.push_back('<');
                    else if (substr == "&frasl") ans.push_back('/');
                    else {
                        ans.append(substr);
                        i--;
                    };
                } else {
                    i = next;
                    ans.append(substr);
                }
            } else ans.push_back(text[i++]);
        };
        return ans;
    }
};