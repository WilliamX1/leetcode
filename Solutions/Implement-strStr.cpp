#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void getNext(string needle, int next[])
    {
        int i = 0, k = -1;
        next[0] = -1;
        while (i < needle.size())
        {
            if (k == -1 || needle[i] == needle[k])
            {
                next[++i] = ++k;
            }
            else k = next[k];
        };
        return;
    }
    int strStr(string haystack, string needle) {
        const int len = needle.length();
        int next[len + 1];
        getNext(needle, next);

        int i = 0, k = 0;
        while (i < haystack.length() && k < len)
        {
            if (k == -1 || haystack[i] == needle[k]){
                i++, k++;
            } else k = next[k];
        };
        if (k == needle.length()) return i - k;
        else return -1;
    }
};

int main()
{
    Solution S;
    cout << S.strStr("sshsefsds", "sefs");
    return 0;
}