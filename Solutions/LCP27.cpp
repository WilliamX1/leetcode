#include <bits/stdc++.h>

using namespace std;
/**
 * 0 -- 1 -- 2 -- 3 ----- x
 * |
 * 9
 * |
 * 8
 * |
 * y
*/
class BlackBox {
private:
    int board0, board1, board2, board3, board4;
    unordered_map<string, int> next_point;
public:
    int axis_to_number(const int& x, const int& y) {
        if (y == 0) return x;
        if (y == ymax) return board3 - x;
        if (x == 0) return board4 - y;
        if (x == xmax) return xmax + y;
        return 0;
    };
    void number_to_axis(const int& number, int& x, int& y) {
        if (number <= board1) {
            x = number, y = 0;
        } else if (board1 < number && number <= board2) {
            x = xmax, y = number - xmax;
        } else if (board2 < number && number <= board3) {
            x = 2 * xmax + ymax - number, y = ymax;
        } else {
            x = 0, y = 2 * (xmax + ymax) - number;
        };
    };
    bool check_inside(int x, int y) {
        return 0 <= x && x <= xmax && 0 <= y && y <= ymax;
    };
    string build_string(int x, int y, int direction) {
        return to_string(x) + ' ' + to_string(y) + ' ' + to_string(direction);
    }

    int reflect(int x, int y, int direction) {
        int ans_x, ans_y, number = axis_to_number(x, y);
        if (direction == -1) {
            /* y = x + yy - xx */
            if (xmax < number && number < board3) {
                /* y == 0 || x == 0 */
                ans_x = x - y, ans_y = 0;
                if (check_inside(ans_x, ans_y)) {} 
                else {
                    ans_x = 0, ans_y = y - x;
                };
            } else {
                /* y == ymax || x == xmax */
                ans_x = ymax + x - y, ans_y = ymax; 
                if (check_inside(ans_x, ans_y)) {} 
                else {
                    ans_x = xmax, ans_y = xmax + y - x;
                };
            };
        } else {
            /* y = -x + x + y */
            if (0 < number && number < board2) {
                /* x == 0 || y == ymax */
                ans_x = 0, ans_y = x + y;
                if (check_inside(ans_x, ans_y)) {}
                else {
                    ans_x = x + y - ymax, ans_y = ymax;
                };
            } else {
                /* x == xmax || y == 0 */ 
                ans_x = xmax, ans_y = -xmax + x + y;
                if (check_inside(ans_x, ans_y)) {} 
                else {
                    ans_x = x + y, ans_y = 0;
                };
            };
        }
        return axis_to_number(ans_x, ans_y);
    };
    
    int get_answer(int x, int y, int direction) {
        int next_number = next_point.find(build_string(x, y, direction))->second;
        while (!state.find(next_number)->second) {
            number_to_axis(next_number, x, y);
            direction = -direction;
            next_number = next_point.find(build_string(x, y, direction))->second;
        };
        return next_number;
    }
    int xmax, ymax;
    unordered_map<int, bool> state;
public:
    BlackBox(int n, int m) {
        int totle = (n + m) << 1;
        
        xmax = m, ymax = n;
        board0 = 0, board1 = xmax, board2 = xmax + ymax;
        board3 = 2 * xmax + ymax,  board4 = 2 * (xmax + ymax);
        
        int x, y;
        for (int i = 0; i < totle; i++) {
            state.insert(make_pair(i, false));
            number_to_axis(i, x, y);
            next_point.insert(make_pair(build_string(x, y, -1), reflect(x, y, -1)));
            next_point.insert(make_pair(build_string(x, y, 1), reflect(x, y, 1)));
        }
        
        return;
    } 
    
    int open(int index, int direction) {
        state.find(index)->second = true;

        int x, y;
        number_to_axis(index, x, y);
        return get_answer(x, y, direction);
    }
    
    void close(int index) {
        state.find(index)->second = false;
    }
};

int main() {
    BlackBox B(2, 3);
    cout << B.open(4, -1);
    cout << B.open(0, -1);
    return 0;
}
/**
 * Your BlackBox object will be instantiated and called as such:
 * BlackBox* obj = new BlackBox(n, m);
 * int param_1 = obj->open(index,direction);
 * obj->close(index);
 */