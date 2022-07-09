#include <iostream>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

int main()
{
    int a, b, d;
    cin >> a >> b >> d;

    if (!a && !b)
        cout << 0 << ' ' << 0 << endl;
    else
    {
        double x = a, y = b, degree = d;
        double r = sqrt(pow(x, 2) + pow(y, 2));
        double sin1 = y / r, cos1 = x / r;
        double sin2 = sin(degree * PI / 180), cos2 = cos(degree * PI / 180);

        // cout << "sin1: " << sin1 << " cos1: " << cos1 << " sin2: " << sin2 << " cos2: " << cos2 << endl;

        double xx = r * (cos1 * cos2 - sin1 * sin2), yy = r * (sin1 * cos2 + sin2 * cos1);
        printf("%.18f %.18f", xx, yy);
    };
    return 0;
}