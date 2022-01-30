#include <iostream>

using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    if (a <= 0 || b <= 0){
        cout << "error";
        return 0;
    }

    int res = 0;
    for (int i = a; i <= b; i++)
    {
        int tmp = i;
        int sum = 0;
        while(tmp){
            sum += (tmp % 10) * (tmp % 10) * (tmp % 10);
            tmp /= 10;
        }
        if (i == sum)
        {
            res++;
            cout << i << endl;
        }
    }
    if (!res) cout << "no";
    return 0;
}
