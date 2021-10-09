
#include <iostream>
using namespace std;

class linkList {
private:
    struct node {  // 内嵌类
        int data;
        node* next;
        explicit node(int x, node* p = NULL) {
            data = x;
            next = p;
        }
        node() :next(NULL) {}
        ~node() {}
    };  // 注意有2个构造函数
    node* head;
    int N = 0; /* 节点数量*/
public:
    //根据自身需求增加或者减少成员函数/成员变量
    linkList() {
        head = new node(); /* 哨兵 */
    };
    ~linkList() {
        delete head;
    }
    int search(const int x) {
        int idx = -1;
        node* ptr = head;
        while (ptr->next && ++idx) {
            ptr = ptr->next;
            if (ptr->data == x) break;
        };
        return idx;
    } // 根据数据返回node的下标
    node* visit(int i) {
        node* ptr = head;
        for (int j = 0; j <= i && ptr; j++) {
            ptr = ptr->next;
        };
        return ptr;
    } // 根据node下标返回node的指针
    void insert(int i, int x) {
        node* ptr = visit(i - 1);
        if (ptr) {
            ptr->next = new node(x, ptr->next);
            N++;
        };
        return;
    } // 在下标为i处插入data为x的点
    void setPtrForLastNode(int pos) {
        node* tail = visit(N - 1);
        if (pos == -1 || pos == tail->data) return;
        else tail->next = visit(pos);
        return;
    } // 让最后一个node指向下标为pos的node，若最后一个node指向自身，或者pos值为-1，则设为nullptr
    int hasCycle() {
        node* ptr1 = head, *ptr2 = head;
        do {
            if (ptr1 == nullptr || ptr2 == nullptr) break;
            ptr1 = ptr1->next;

            /* ptr2 比较快 */
            ptr2 = ptr2->next; if (ptr2 == nullptr) break;
            ptr2 = ptr2->next;
        } while (ptr2 != nullptr && ptr1 != ptr2);
        return ptr2 != nullptr;
    } // 让两个指针以不同速度遍历链表，如果两个指针可以相遇那么存在环路
};


int main() {
    linkList link_list = linkList();
    int n;
    cin >> n; // 读取node的个数
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        // 处理接受的数据
        link_list.insert(i, data);
    }
    int pos;
    cin >> pos; // 读取最后一个node指向的node的index
    link_list.setPtrForLastNode(pos);
    // 用链表构建有向图

    // 判断环路
    std::cout << link_list.hasCycle();
}