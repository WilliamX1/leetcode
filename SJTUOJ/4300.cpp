#include <iostream>
using namespace std;

struct Node
{
	int data;
	int weight;
	Node() :weight(0), data(0) {};
};
int main()
{
	int N = 0, tmp = 0;
	cin >> N;
	Node* COW = new Node[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		COW[i].data = tmp;
		for (int j = i; j >= 0; --j)
		{
			if (tmp < COW[j].data)
				COW[j].weight += 1;
			else if (tmp > COW[j].data)
				COW[i].weight += 1;
		}
	}
	for (int i = 0; i < N; ++i)
		if (COW[i].weight == N / 2)
		{
			cout << COW[i].data;
			return 0;
		}
	return 0;
}