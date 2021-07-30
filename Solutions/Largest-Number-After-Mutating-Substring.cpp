class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool flag = false;
        int len = num.size();
        for (int i = 0; i < len; i++)
        {
            int ele = num[i] - '0';
            if (flag) {
                if (ele <= change[ele]) num[i] = change[ele] + '0';
                else break;
            } else {
                if (ele < change[ele]) num[i] = change[ele] + '0', flag = true;
                else continue;
            };
        };
        return num;
    }
};