#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int x, y;
    int MAX, MIN, MID;
    while(scanf("%d%d", &x, &y) != EOF)
    {
        MAX = max(x, y);
        MIN = min(x, y);
        while(MIN != 0)
        {
            MID = MAX % MIN;
            MAX = MIN;
            MIN = MID;
        }
        printf("%d\n", MAX);
    }
    return 0;
}
