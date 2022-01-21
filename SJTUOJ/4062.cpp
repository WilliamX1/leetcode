#include <iostream>
using namespace std;

int main()
{
    long long int x, y; cin >> x >> y;
    long long int max, min;
    if (x == y)
    {
        cout << 4 * x;
        return 0;
    }
    long long int sum = 0;
    
    do
    {
        max = x > y ? x : y;
        min = x < y ? x : y;
        sum += 4 * min;
        x = min;
        y = max - min;
    } while (x != y);
    sum += 4 * x;
    cout << sum;
    return 0;
}
