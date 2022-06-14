#include <algorithm>
#include <iostream>
#include <list>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string largestNumber(vector<int> &nums)
    {
        int num_size = nums.size();
        vector<string> tmp;
        for (int i = 0; i < num_size; i++)
            tmp.push_back(to_string(nums[i]));

        sort(tmp.begin(), tmp.end(), myCompare);

        string res = "";
        for (int i = 0; i < num_size; i++)
            res = res + tmp[i];
        /*删除前导0*/
        while (res.size() > 1 && res[0] == '0')
            res = res.substr(1);
        return res;
    }
    static bool myCompare(const string A, const string B)
    {
        return A + B > B + A;
        /*以下程序不知道为什么会出bug*/
        // volatile int size = min(A.size(), B.size());
        // for (int i = 0; i < size; i++)
        //     if (A[i] != B[i]) return A[i] > B[i];

        // if (A.size() > size) return myCompare(A.substr(size), B);
        // else if (B.size() > size) return myCompare(A, B.substr(size));
        // else return true;
    }
};

int main()
{
    Solution S;
    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << S.largestNumber(v);
    return 0;
}