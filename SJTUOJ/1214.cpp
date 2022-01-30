
#include <iostream>
using namespace std;

class childBrotherTree
{
public:
	struct CBNode
	{
		int key;
		int left;
		int bro;
	};
	class linkQueue
	{
	public:
		struct Node
		{
			Node* next;
			int data;
			Node() :data(0), next(NULL) {};
			Node(int x, Node* t = NULL) :data(x), next(t) {};
		};
		Node* root;
		Node* rear;
		linkQueue() { root = rear = NULL; };
		~linkQueue() {};
		void enQueue(const int& x) {
			if (root == NULL)
			{
				rear = root = new Node(x);
				return;
			}
			rear = rear->next = new Node(x);
		}
		int deQueue()
		{
			if (root == NULL) return -1;
			Node* tmp = root;
			int thedata = tmp->data;
			root = root->next;
			delete tmp;
			return thedata;
		}
		bool isEmpty() { return root == NULL; }
	};
	int length;  //数组长度
	int head; 
	CBNode* array;
	linkQueue preQueue;
	linkQueue postQueue;
	void preOrder(const CBNode& x)
	{
		cout << x.key << " ";
		if (x.left) preOrder(array[x.left]);
		if (x.bro) preOrder(array[x.bro]);
		return;
	}
	void preOrder()
	{
		preOrder(array[head]);
	};
	void postOrder(const CBNode& x)
	{
		if (x.left) postOrder(array[x.left]);
		cout << x.key << " ";
		if (x.bro) postOrder(array[x.bro]);
		return;
	}
	void postOrder()
	{
		postOrder(array[head]);
	}
	void levelOrder()
	{
		linkQueue QUE;
		QUE.enQueue(head);
		for (int i = 1; i <= length; ++i)
		{
			int tmpNum = QUE.deQueue();
			cout << array[tmpNum].key << " ";
			if (array[tmpNum].left)
			{
				int theleft = array[tmpNum].left;
				QUE.enQueue(theleft);
				int thebro = array[theleft].bro;
				while (thebro)  //左儿子的兄弟全部进队
				{
					QUE.enQueue(thebro);
					thebro = array[thebro].bro;
				}
			};
		}
	};
	childBrotherTree()
	{
		array = NULL;
		int N = 0, i = 0, left, brother, thekey;
		cin >> N;
		length = N;
		array = new CBNode[N + 1];
		for (i = 1; i <= N; ++i) {
			cin >> left >> brother >> thekey;
			array[i].left = left;
			array[i].bro = brother;
			array[i].key = thekey;
		};
		findHead();
	};
	void findHead()
	{
		int i = 0;
		bool* flag = new bool[length + 1];
		for (i = 1; i <= length; ++i) { flag[i] = true; };
		for (i = 1; i <= length; ++i)
		{
			flag[array[i].bro] = false;
			flag[array[i].left] = false;
		}
		for (i = 1; i <= length; ++i)
      	{
			if (flag[i] == true)
			{
				head = i;
				return;
			}
		}
	}
	~childBrotherTree() {};
};

int main()
{
	childBrotherTree TREE;
	TREE.preOrder();
	cout << endl;
	TREE.postOrder();
	cout << endl;
	TREE.levelOrder();
}