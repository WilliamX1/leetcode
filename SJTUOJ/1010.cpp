#include <iostream>

using namespace std;

int main()
{
    int Month[13];
    for (int i = 1; i <= 12; i++) cin >> Month[i];

    int remain = 0;
    int res = 0;
    for (int i = 1; i <= 12; i++){
        remain += 300;
        if (remain < Month[i]){
            cout << '-' << i;
            return 0;
        }
        res += (remain - Month[i]) / 100;
        remain = (remain - Month[i]) % 100;
    }
    cout << res * 100 * (1 + 0.2) + remain;
    return 0;
}
