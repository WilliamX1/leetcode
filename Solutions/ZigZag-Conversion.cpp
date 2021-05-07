#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<char> v[numRows];
        int row = 0, column = 0, state = 0;
        for (int i = 0; i < s.size(); i++)
        {
            v[row].push_back(s[i]);
            if (state == 0) { //向下
                if (row == numRows - 1) {
                    state = 1;
                    row--;
                    column++;
                } else row++;
            } else if (state == 1) {
                if (row == 0) {
                    state = 0;
                    row++;
                } else {
                    row--;
                    column++;
                }
            }
        };
        string res = "";
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < v[i].size(); j++)
                res = res + v[i][j];
        return res;
    }
};

int main()
{
    Solution S;
    cout << S.convert("AB", 1);
    return 0;
}