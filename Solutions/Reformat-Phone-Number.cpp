class Solution {
public:
    string reformatNumber(string number) {
        string nums;
        for (const char& ch : number)
            if ('0' <= ch && ch <= '9')
                nums += ch;
        int n = nums.size(), index = 0;
        string ans;
        while (index < n - 4) {
            ans += nums.substr(index, 3) + "-";
            index += 3;
        };
        if (n - index == 4) {
            ans += nums.substr(index, 2) + "-" + nums.substr(index + 2, 2);
        } else if (index < n) ans += nums.substr(index);
        else ans.pop_back();
        return ans;
    }
};