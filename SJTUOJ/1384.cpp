#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    char str[10000000 + 1];
    scanf("%s", &str);
    int len = strlen(str);
    int v_pre_0 = 0, v_pre_1 = 0, v_cur_0 = 0, v_cur_1 = 0, v_next_0 = -1, v_next_1 = -1;
    for (int i = 0; i < len; i++)
    {
        if ('a' <= str[i] && str[i] <= 'z') {
            v_next_0 = min(v_cur_0, v_cur_1);
            v_next_1 = v_cur_1 + 1;
        } else {
            v_next_0 = min(v_cur_0, v_cur_1) + 1;
            v_next_1 = v_cur_1;
        };
        v_pre_0 = v_cur_0; v_pre_1 = v_cur_1;
        v_cur_0 = v_next_0; v_cur_1 = v_next_1;
    };
    std::cout << min(v_cur_0, v_cur_1);
    return 0;
}