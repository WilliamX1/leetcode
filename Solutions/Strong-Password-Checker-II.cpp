class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int i = 0, n = password.size();
        if (password.size() < 8) return false;
        
        for (i = 0; i < n; i++)
            if ('a' <= password[i] && password[i] <= 'z')
                break;
        if (i >= n) return false;
        for (i = 0; i < n; i++)
            if ('A' <= password[i] && password[i] <= 'Z')
                break;
        if (i >= n) return false;
        for (i = 0; i < n; i++)
            if ('0' <= password[i] && password[i] <= '9')
                break;
        if (i >= n) return false;

        string special = "\"!@#$%^&*()-+\"";
        bool flag = false;
        for (i = 0; i < n; i++)
            for (char ch : special)
                if (password[i] == ch) {
                    flag = true;
                    break;
                };
        if (flag == false) return false;
        for (i = 1; i < n; i++)
            if (password[i] == password[i - 1])
                return false;
        return true;
    }
};