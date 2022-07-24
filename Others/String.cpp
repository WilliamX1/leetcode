#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;

    int Aptr = n - 1, Bptr = n - 1;
    while (Bptr >= 0 && Aptr >= 0)
    {
        if (A[Aptr] == B[Bptr])
        {
            Aptr--;
            Bptr--;
        }
        else
            Aptr--;
    };
    cout << n - (n - 1 - Bptr) << endl;
    return 0;
}