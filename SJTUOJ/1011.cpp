#include <iostream>

using namespace std;

class MyComplex
{
private:
    double x, y;
public:
    MyComplex(double t_x, double t_y):x(t_x), y(t_y){};
    MyComplex(){};
    friend MyComplex operator+(const MyComplex z1, const MyComplex z2)
    {
        double x = z1.x + z2.x;
        double y = z1.y + z2.y;
        return MyComplex(x, y);
    };
    friend MyComplex operator-(const MyComplex z1, const MyComplex z2)
    {
        double x = z1.x - z2.x;
        double y = z1.y - z2.y;
        return MyComplex(x, y);
    };
    friend MyComplex operator*(const MyComplex z1, const MyComplex z2)
    {
        double x = z1.x * z2.x - z1.y * z2.y;
        double y = z1.x * z2.y + z1.y * z2.x;
        return MyComplex(x, y);
    };
    friend MyComplex operator/(const MyComplex z1, const MyComplex z2)
    {
        double c2d2 = z2.x * z2.x + z2.y * z2.y;
        double x = z1.x * z2.x + z1.y * z2.y; x /= c2d2;
        double y = z1.y * z2.x - z1.x * z2.y; y /= c2d2;
        return MyComplex(x, y);
    };
    MyComplex operator+=(const MyComplex z2)
    {
        x += z2.x;
        y += z2.y;
        return *this;
    };
    MyComplex operator-=(const MyComplex z2)
    {
        x -= z2.x;
        y -= z2.y;
        return *this;
    };
    MyComplex operator*=(const MyComplex z2)
    {
        double t_x = x * z2.x - y * z2.y;
        double t_y = x * z2.y + y * z2.x;
        x = t_x, y = t_y;
        return *this;
    };
    MyComplex operator/=(const MyComplex z2)
    {
        double c2d2 = z2.x * z2.x + z2.y * z2.y;
        double t_x = (x * z2.x + y * z2.y) / c2d2;
        double t_y = (y * z2.x - x * z2.y) / c2d2;
        x = t_x, y = t_y;
        return *this;
    };
    friend ostream& operator<<(ostream& out, const MyComplex z)
    {
        printf("%.2f %.2f", z.x, z.y);
        return out;
    };
    friend istream& operator>>(istream& in, MyComplex& z)
    {
        in >> z.x >> z.y;
        return in;
    };
};

int main()
{
    MyComplex z1;
    MyComplex z2;

    cin >> z1 >> z2;

    cout << z1 + z2 << endl;
    cout << z1 - z2 << endl;
    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    cout << (z1 += z2) << endl;
    cout << (z1 -= z2) << endl;
    cout << (z1 *= z2) << endl;
    cout << (z1 /= z2) << endl;

    return 0;
}
