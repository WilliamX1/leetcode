#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct task {
        int begin_time;
        int end_time;
        int index;
        task(){};
        task(int b, int e, int i) : begin_time(b), end_time(e), index(i) {};
        static bool compare_with_begintime(task A, task B) {
            if (A.begin_time != B.begin_time) return A.begin_time > B.begin_time;
            else {
                if (A.end_time != B.end_time) return A.end_time > B.end_time;
                else return A.index > B.index;
            }
        };
        static bool compare(task A, task B) {
            if (A.end_time - A.begin_time != B.end_time - B.begin_time) return A.end_time - A.begin_time > B.end_time - B.begin_time;
            else return A.index > B.index;
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int _size = tasks.size();
        vector<task> _task; //任务队列
        for (int i = 0; i < _size; i++)
            _task.push_back(task(tasks[i][0], tasks[i][0] + tasks[i][1], i));
        sort(_task.begin(), _task.end(), task::compare_with_begintime);

        deque<task> _deque; //等待队列
        vector<int> _res; //答案队列
        _deque.push_front(_task.back()); _task.pop_back(); //将第一个任务压入栈
        int time = _deque.front().begin_time; //CPU时间

        while (!_deque.empty()) {
            time += _deque.back().end_time - _deque.back().begin_time;

            while (!_task.empty() && _task.back().begin_time <= time) {
                _deque.push_front(_task.back());
                _task.pop_back();
            };
            _res.push_back(_deque.back().index);
            _deque.pop_back();

            /*如果等待队列为空，检查任务队列并将最新任务push进等待队列*/
            if (_deque.empty() && !_task.empty()) {
                _deque.push_back(_task.back());
                _task.pop_back();
            }
            /*对等待队列进行排序*/
            sort(_deque.begin(), _deque.end(), task::compare);
        };
        return _res;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> v = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    vector<int> res = S.getOrder(v);
    return 0;
}