#include <iostream>

using namespace std;

int main()
{
    string str;
    char sstr[3];

    while(cin >> str >> sstr[0] >> sstr[1] >> sstr[2])
    {
        int xb = 0;
        for (int i = 1; str[i] != '\0'; i++)
            if (str[i] > str[xb]) xb = i;

        int i;
        for (i = 0; i <= xb; i++)
            printf("%c", str[i]);
        printf("%c%c%c", sstr[0], sstr[1], sstr[2]);
        for (; str[i] != '\0'; i++)
            printf("%c", str[i]);
        printf("\n");
    }
    return 0;
}
