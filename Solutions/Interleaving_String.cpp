#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1 == "") return s2 == s3;
        if (s2 == "") return s1 == s3;
        if (s3 == "") return false;

        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;

        vector< vector<int> > v(len1 + 1, vector<int>(len2 + 1, 0));
        
        v[0][0] = true;
        for (int i = 0; i <= len1; i++)
            for (int j = 0; j <= len2; j++)
            {
                int p = i + j - 1;
                if (i > 0) v[i][j] |= (v[i - 1][j] && s1[i - 1] == s3[p]);
                if (j > 0) v[i][j] |= (v[i][j - 1] && s2[j - 1] == s3[p]);
            };
        return v[len1][len2];
    }
};