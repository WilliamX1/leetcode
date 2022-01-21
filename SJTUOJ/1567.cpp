#include <iostream>

using namespace std;

int main()
{
    char ch;
    int n, line;
    cin >> ch >> n;

    for (int i = 1; i <= n; i++)
    {
        line = min(i, n + 1 - i);
        for (int j = 1; j <= (n + 1) / 2 - line; j++) printf(" ");
        for (int j = 1; j <= 2 * line - 1; j++) printf("%c", ch);
        printf("\n");
    }
    return 0;
}
