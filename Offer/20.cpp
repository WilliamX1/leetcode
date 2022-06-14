class Solution
{
  public:
    bool isDecimalExpInteger(string s)
    {
        int idx = 0, len = s.size(), tmp_idx = 0;
        while (idx < len && isBlank(s[idx]))
            idx++;
        tmp_idx = whereDecimal(s.substr(idx));
        if (tmp_idx < 0)
            return false;
        else
            idx += tmp_idx;
        if (idx < len && isExp(s[idx]))
        {
            idx++;
            tmp_idx = whereInteger(s.substr(idx));
            if (tmp_idx < 0)
                return false;
            else
                idx += tmp_idx;
        };
        while (idx < len && isBlank(s[idx]))
            idx++;
        return idx == len;
    };
    bool isIntegerExpInteger(string s)
    {
        int idx = 0, len = s.size(), tmp_idx = 0;
        while (idx < len && isBlank(s[idx]))
            idx++;
        tmp_idx = whereInteger(s.substr(idx));
        if (tmp_idx < 0)
            return false;
        else
            idx += tmp_idx;
        if (idx < len && isExp(s[idx]))
        {
            idx++;
            tmp_idx = whereInteger(s.substr(idx));
            if (tmp_idx < 0)
                return false;
            else
                idx += tmp_idx;
        };
        while (idx < len && isBlank(s[idx]))
            idx++;
        return idx == len;
    };
    bool isNumber(string s)
    {
        return isDecimalExpInteger(s) || isIntegerExpInteger(s);
    };
    int whereDecimal(string s)
    {
        int len = s.size();
        if (len == 0)
            return -1;
        else
        {
            int idx = 0;
            if (isSign(s[idx]))
                idx++;
            if (idx < len && isDot(s[idx]))
            {
                idx++;
                if (idx == len || !isDigit(s[idx]))
                    return -1;
                else
                    idx++;
                while (idx < len && isDigit(s[idx]))
                    idx++;
            }
            else if (idx < len && isDigit(s[idx]))
            {
                idx++;
                while (idx < len && isDigit(s[idx]))
                    idx++;
                if (idx < len && isDot(s[idx]))
                    idx++;
                while (idx < len && isDigit(s[idx]))
                    idx++;
            }
            else
                return -1;
            return idx;
        }
    };
    int whereInteger(string s)
    {
        int len = s.size();
        if (len == 0)
            return -1;
        else
        {
            int idx = 0;
            if (isSign(s[idx]))
                idx++;
            if (idx >= len || !isDigit(s[idx]))
                return -1;
            else
            {
                while (idx < len && isDigit(s[idx]))
                    idx++;
                return idx;
            }
        }
    };
    bool isBlank(char ch)
    {
        return ch == ' ';
    };
    bool isSign(char ch)
    {
        return ch == '+' || ch == '-';
    };
    bool isExp(char ch)
    {
        return ch == 'e' || ch == 'E';
    };
    bool isDigit(char ch)
    {
        return '0' <= ch && ch <= '9';
    };
    bool isDot(char ch)
    {
        return ch == '.';
    };
};