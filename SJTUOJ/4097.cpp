#include <iostream>
#include <cstdio>
using namespace std;

class linkList
{
	struct node
	{
		node* next;
		int data;
		node(int d, node* n = NULL) :data(d),next(n) {};
	};
	node* head;
	int maxSize;
public:
	linkList(int N, int* array)
	{
		head = new node(-1);  //head为哨兵
		node* cur = head;
		for (int i = 1; i <= N; i++)
			cur = cur->next = new node(array[i]);
		maxSize = N;
	}
	void insert(int x, int y)
	{
		node* tmp_cur = head;
		for (int i = 0; i < x; i++)
			tmp_cur = tmp_cur->next;
		tmp_cur->next = new node(y,tmp_cur->next);
		maxSize += 1;
	}
	void deQueue(int x)
	{
		node* tmp_pre = head;
		node* delt;
		for (int i = 0; i < x - 1; i++)
			tmp_pre = tmp_pre->next;
		delt = tmp_pre->next;
		tmp_pre->next = delt->next;
		delete delt;
		maxSize -= 1;
	}
	void traverse()
	{
		node* cur = head;
		for (int i = 1; i <= maxSize; i++)
		{
			cur = cur->next;
			cout << cur->data << " ";
		}
	}
};

int main()
{
	int N, M; cin >> N >> M;
	int choice, x, y;
	int* array = new int[N + 1];
	for (int i = 1; i <= N; i++)
		cin >> array[i];
	linkList L(N, array);
	for (int i = 1; i <= M; i++)
	{
		cin >> choice;
		if (choice == 1)
		{
			cin >> x >> y;
			L.insert(x, y);
		}
		else if (choice == 2)
		{
			cin >> x;
			L.deQueue(x);
		}
	}
	L.traverse();
	return 0;
}