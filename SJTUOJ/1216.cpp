#include <iostream>
#include <cstring>
using namespace std;

class heap
{
private:
	int* array;
	int currentSize;
	int maxSize;
public:
	heap(int N = 100)
	{
		maxSize = N;
		array = new int[N];
		currentSize = 0;
	}
	void doubleSpace()
	{
		int* tmp = array;
		array = new int[3 * maxSize];
		for (int i = 1; i <= currentSize; i++)
			array[i] = tmp[i];
		maxSize *= 3;
	}
	void enQueue(const int& x)
	{
		if (currentSize == maxSize - 1)
			doubleSpace();

		array[++currentSize] = x;
		int tmp = x;
		int hole = currentSize;
		for (; hole > 1; hole /= 2)
		{
			if (tmp < array[hole / 2])
				array[hole] = array[hole / 2];
			else
				break;
		}
		array[hole] = tmp;
	}
	void find(const int& x, int cur_xb, int &max_min, int &tar_xb)
	{
		if (array[cur_xb] <= x)
		{
			if (2 * cur_xb <= currentSize)
				find(x, 2 * cur_xb, max_min, tar_xb);
			if (2 * cur_xb + 1 <= currentSize)
				find(x, 2 * cur_xb + 1, max_min, tar_xb);
		}
		else if (array[cur_xb] > x)
		{
			if (array[cur_xb] < max_min)  //如果比大于x的较小值小
			{
				max_min = array[cur_xb];
				tar_xb = cur_xb;
			}
			else if (array[cur_xb] == max_min)  //如果等于大于x的较小值
			{
				if (cur_xb < tar_xb)  //比较下标大小
					tar_xb = cur_xb;
			}
		}
	}
	int findfind(int x)
	{
		int max_min = 500000000;
		int tar_xb = -1;
		for (int i = 1; i <= currentSize; i++)
		{
			if (array[i] > x && array[i] < max_min)
			{
			    max_min = array[i];
				tar_xb = i;
			}
		}
		return tar_xb;
	}
	void decrease(int i, int v)
	{
		array[i] -= v;
		int tmp = array[i];
		
		int hole = i;
		for (; hole > 1; hole /= 2)
		{
			if (tmp < array[hole / 2])
				array[hole] = array[hole / 2];
			else
				break;
		}
		array[hole] = tmp;
	}
};

int main()
{
	heap T(2);
	string choice;
	int x, y, max_min , tar_xb = -1;
	int M; cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> choice;
		if (choice == "insert")
		{
			cin >> x;
			T.enQueue(x);
		}
		else if (choice == "find")
		{
			cin >> x;
			//max_min = 100000000;
			//tar_xb = -1;
			//T.find(x, 1, max_min, tar_xb);
			//cout << tar_xb << endl;
			cout << T.findfind(x) << endl;
		}
		else if (choice == "decrease")
		{
			cin >> x >> y;
			T.decrease(x, y);
		}
	}
	return 0;
}