#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

class NumberContainers
{
  public:
    unordered_map<int, set<int>> pque;
    unordered_map<int, int> actual;
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        actual[index] = number;
        pque[number].insert(index);
    }

    int find(int number)
    {
        set<int> &p = pque[number];

        for (auto iter = p.begin(); iter != p.end();)
        {
            if (number == actual[*iter])
                return *iter;
            else
                iter = p.erase(iter);
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

// int main()
// {
//     // ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
//     // [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
//     NumberContainers ex;
//     cout << ex.find(10) << endl;
//     ex.change(2, 10);
//     ex.change(1, 10);
//     ex.change(3, 10);
//     ex.change(5, 10);
//     cout << ex.find(10) << endl;
//     ex.change(1, 20);
//     cout << ex.find(10) << endl;
//     return 0;
// }