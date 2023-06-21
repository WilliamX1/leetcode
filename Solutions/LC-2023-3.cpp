#include <iostream>
#include <cmath>

using namespace std;


int main() {
    Square s1, s2;
    cout << "Enter the center coordinates and length of the first square: ";
    cin >> s1.center.x >> s1.center.y >> s1.length;
    cout << "Enter the center coordinates and length of the second square: ";
    cin >> s2.center.x >> s2.center.y >> s2.length;
    if (isIntersect(s1, s2)) {
        Point p = getIntersection(s1, s2);
        cout << "The squares intersect at point (" << p.x << ", " << p.y << ")" << endl;
    } else {
        cout << "The squares do not intersect." << endl;
    }
    return 0;
}



class Solution {
public:
    struct Point {
        double x;
        double y;
    };

    struct Square {
        Point center;
        double length;
    };

    bool isIntersect(Square s1, Square s2) {
        double distance = sqrt(pow(s1.center.x - s2.center.x, 2) + pow(s1.center.y - s2.center.y, 2));
        double diagonal = sqrt(2) * (s1.length / 2 + s2.length / 2);
        if (distance <= diagonal) {
            return true;
        }
        return false;
    }

    Point getIntersection(Square s1, Square s2) {
        Point p;
        p.x = (s1.center.x + s2.center.x) / 2;
        p.y = (s1.center.y + s2.center.y) / 2;
        return p;
    }

    

    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        int64_t n = forceField.size(), ans = 0;
        for (int64_t i = 0; i < n; i++) {
            int64_t x = 2 * forceField[i][0], y = 2 * forceField[i][1], size = forceField[i][2];

            for (int64_t xx = x - size; xx <= x + size; xx += 2 * size)
                for (int64_t yy = y - size; yy <= y + size; yy += 2 * size) {
                    int64_t tmp = 0;

                    // xx <= another_x + another_size / 2 && yy <= another_y + size / 2
                    // xx >= another_x - another_size / 2 && yy >= another_y - another_size / 2
                    for (int64_t j = 0; j < n; j++) {
                        int64_t another_x = 2 * forceField[j][0], another_y = 2 * forceField[j][1], another_size = forceField[j][2];
                        if (xx <= another_x + another_size && yy <= another_y + another_size 
                            && xx + another_size >= another_x && yy + another_size >= another_y)
                            tmp++;
                    };

                    if (tmp > ans) {
                        cout << i << ' ' << xx << ' ' << yy << ' ' << tmp << endl;
                        ans = max(ans, tmp);
                    }
                }
        }
        return ans;
    };
};