#include <iostream>
using namespace std;

struct Node
{
	int left, right, parent;
	Node* next;
	Node() :next(NULL), left(-1), right(-1),parent(-1) {};
};
class linkQueue
{
private:
	Node* rear;
	Node* head;
public:
	linkQueue(Node& t) { head = rear = &t; };
	void enQueue(Node& t) {
		if (head == NULL)
			head = rear = &t;
		else
			rear = rear->next = &t;
	}
	Node* deQueue() {
		Node* tmp = head;
		head = head->next;
		return tmp;
	}
};
int main()
{
	int N; cin >> N;
	int parent;
	if (N == 1)
	{
		cout << "true";
		return 0;
	}
	Node* array = new Node[N];
	for (int i = 1; i < N; i++)
	{
		cin >> parent;
		array[i].parent = parent;
		if (array[parent].left == -1)
			array[parent].left = i;
		else
			array[parent].right = i;
	}

	linkQueue tree(array[0]);
	Node* tmp;
	int cur = 0;;
	while (true)
	{
		tmp = tree.deQueue();
		cur += 1;
		if (tmp->left != -1)
			tree.enQueue(array[tmp->left]);
		else
		{
			if (2 * cur == N - 1)
				cout << "true";
			else
				cout << "false";
			break;
		}
		if (tmp->right != -1)
			tree.enQueue(array[tmp->right]);
		else
		{
			if (2 * cur == N)
				cout << "true";
			else
				cout << "false";
			break;
		}
	}
	return 0;
}