#include <iostream>

using namespace std;

int main()
{
    int* Arr = new int[10];
    int* Brr = new int[10];
    int* Crr=  new int[10];

    int i, j, k, m, tmp, sum = 200000;
    for (i = 1; i < 10; i++) cin >> Arr[i];
    for (i = 1; i < 10; i++) Arr[i] /= 3;

    for (i = 0; i <= 3; i++)
        for (j = 0; j <= 3; j++)
            for (k = 0; k <= 3; k++)
            {
                Brr[1] = i; Brr[2] = j; Brr[5] = k;  // 1,2,5联动其他所有

                Brr[3] = 4 - (Brr[1] + Brr[2] + Brr[5] + Arr[2]) % 4;
                Brr[4] = 4 - (Brr[1] + Brr[2] + Arr[1]) % 4;
                Brr[6] = 4 - (Brr[2] + Brr[3] + Arr[3]) % 4;
                Brr[7] = 4 - (Brr[1] + Brr[4] + Brr[5] + Arr[4]) % 4;
                Brr[8] = 4 - (Brr[4] + Brr[7] + Arr[7]) % 4;
                Brr[9] = 4 - (Brr[1] + Brr[3] + Brr[5] + Brr[7] + Arr[5]) % 4;

                for (m = 1; m <= 9; m++) Brr[m] %= 4;

                if ((Brr[3] + Brr[5] + Brr[6] + Brr[9] + Arr[6]) % 4 != 0) continue;
                if ((Brr[5] + Brr[7] + Brr[8] + Brr[9] + Arr[8]) % 4 != 0) continue;
                if ((Brr[6] + Brr[8] + Brr[9] + Arr[9]) % 4 != 0) continue;

                tmp = 0;
                for (m = 1; m <= 9; m++) tmp += Brr[m];
                if (tmp < sum)
                {
                    for (m = 1; m <= 9; m++) Crr[m] = Brr[m];
                    sum = tmp;
                }
            }
    for (i = 1; i <= 9; i++)
        for (j = 1; j <= Crr[i]; j++)
            cout << i << " ";
    return 0;
}
