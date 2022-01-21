#include <iostream>
using namespace std;

class linkQueue
{
private:
	struct Node
	{
		Node* next;
		int data;
		Node(int thedata = 0, Node* thenext = NULL) :data(thedata), next(thenext) {};
	};
	Node* head;
	Node* rear;
public:
	linkQueue() { head = rear = NULL; };
	void enQueue(const int& x)
	{
		if (head == NULL)
			rear = head = new Node(x);
		else
			rear = rear->next = new Node(x);
	}
	int deQueue()
	{
		Node* tmp = head;
		int thedata = tmp->data;
		head = head->next;
		delete tmp;
		return thedata;
	}
	bool isEmpty() { return head == NULL; };
};
class bernolli
{
private:
	int* array;
	int maxSize;
	int currentSize;
public:
	bernolli(int capacity = 100)
	{
		array = new int[capacity + 1];
		maxSize = capacity;
		currentSize = 0;
	}
	~bernolli() {};
	void enQueue(const int& x)
	{
		int hole = ++currentSize;
		for (; hole > 1 && x < array[hole / 2]; hole /= 2)
			array[hole] = array[hole / 2];
		array[hole] = x;
	}
	int deQueue()
	{
		int minItem = array[1];
		array[1] = array[currentSize--];
		percolateDown(1);
		return minItem;
	}
	void percolateDown(int hole)
	{
		int child;
		int tmp = array[hole];

		for (; hole * 2 <= currentSize; hole = child)
		{
			child = hole * 2;
			if (child != currentSize && array[child + 1] < array[child])
				child++;
			if (array[child] < tmp) array[hole] = array[child];
			else break;
		}
		array[hole] = tmp;
	}
	int getHead() { return array[1]; };
};
int main()
{
	int N = 0;
	cin >> N;
	string str; int tmp;
	linkQueue STORE;
	bernolli TREE(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		if (str == "insert")
		{
			cin >> tmp;
			TREE.enQueue(tmp);
		}
		else if (str == "delete")
			TREE.deQueue();
		else if (str == "min")
			STORE.enQueue(TREE.getHead());
	}
	while (!STORE.isEmpty())
	{
		cout << STORE.deQueue() << endl;
	}
	return 0;
}