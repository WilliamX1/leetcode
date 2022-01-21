#include <iostream>
using namespace std;

int main()
{
		int N, M; cin >> N >> M;
		int* array = new int[N + 1];
		int* store = new int[N + 1]; int num = 0;
		char tmp;
		int A, B;
		for (int i = 1; i <= N; i++) { cin >> array[i]; };
		for (int i = 0; i < M; i++)
		{
			cin >> tmp;
			if (tmp == 'Q')
			{
				cin >> A >> B;
				int max = -1;
				for (int j = A; j <= B; j++)
					if (array[j] >= max)
						max = array[j];
				store[++num] = max;
			}
			else if (tmp == 'U')
			{
				cin >> A >> B;
				array[A] = B;
			}
		}
		for (int i = 1; i <= num; i++)
			cout << store[i] << endl;

	return 0;
}