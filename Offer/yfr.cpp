// class Solution {
// private:
//     int f(int m, int n) {
//         if (m == 1) return 0;
//         int x = f(m - 1, n);
//         return (x + n) % m;
//     };
// public:
//     int lastRemaining(int m, int n) {
//         return f(m, n) + 1;
//     };
// };
#include <iostream>

using namespace std;

class Employee
{
  private:
    int number;
    Employee *next;

  public:
    static int solution(int m, int n)
    {
        /* 特殊情况判断 */
        if (m == 1)
            return m;
        /* 构造循环单链表 */
        Employee *head = new Employee(1), *ptr1 = head;
        for (int i = 2; i <= m; i++)
            ptr1 = ptr1->next = new Employee(i);
        ptr1->next = head; /* 头尾相接 */

        Employee *ptr2 = head;
        for (int i = m; i > 1; i--)
        {
            for (int j = 0; j < n - 2; j++)
                ptr2 = ptr2->get_next();
            /* 寻找得到即将被删除结点的前一个节点 */
            ptr2->set_next(ptr2->next->next); /* 将该节点的下一个节点置为下下个节点 */
            ptr2 = ptr2->next;                /* 下次计数从该节点新的下一个节点开始 */
        }
        return ptr2->get_number();
    };
    Employee(int num)
    {
        this->number = num;
        this->next = nullptr;
    };
    int get_number()
    {
        return this->number;
    };
    void set_next(Employee *next_employee)
    {
        /* 将当前节点下一个节点置为替换为 next_employee
         * 并把原来下一个节点删除
         */
        Employee *origin_next_employee = this->next;
        this->next = next_employee;
        delete origin_next_employee;
        return;
    };
    Employee *get_next()
    {
        return this->next;
    };
};

int main()
{
    int m = 190, n = 8;
    while (cin >> m >> n)
    {
        std::cout << Employee::solution(m, n);
    };
    return 0;
}