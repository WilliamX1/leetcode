// 2105.最大矩形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
struct node
{
	long long int xb;
	long long int num;
};
int main()
{
	int N; cin >> N;
	long long int max = 0;
	int cur_xb = 0;
	int x, y;
	node* array = new node[N + 1]; array[0].xb = 0;

	for (int i = 1; i < N + 1; i++)
	{
		cin >> x;
        y = array[cur_xb].xb;
		for (int j = cur_xb; j > 0 && array[j].num > x; j--)
		{		
			max = max > array[j].num * (y - array[j - 1].xb) ? max : array[j].num * (y - array[j - 1].xb);
			cur_xb--;
		}
		cur_xb++;
		array[cur_xb].xb = i;
		array[cur_xb].num = x;
	}

	y = array[cur_xb].xb;
	for (int j = cur_xb; j > 0 && array[j].num > -1; j--)
	{
		max = max > array[j].num * (y - array[j - 1].xb) ? max : array[j].num * (y - array[j - 1].xb);
		cur_xb--;
	}

	cout << max;
	return 0;
}
