#include <iostream>
using namespace std;

struct M
{
	int score;  //分数
	int Mus;  //力量
	int data; //编号
};
int divide(M* A, int left, int right)
{
	M k = A[right];
	do
	{
		while (left < right && A[left].score > k.score) ++left;
		while (left < right && A[left].score == k.score && A[left].data < k.data) ++left;
		if (left < right) { A[right] = A[left]; right--; };
		while (left < right && A[right].score < k.score) --right;
		while (left < right && A[right].score == k.score && A[right].data > k.data) --right;
		if (left < right) { A[left] = A[right]; left++; };
	} while (left != right);
	A[right] = k;
	return right;
}
void quickSort(M* A, int left, int right)
{
	if (left >= right) return;
	int mid = divide(A, left, right);
	quickSort(A, left, mid - 1);
	quickSort(A, mid + 1, right);
}

int main()
{
	int N, R; cin >> N >> R;
	N = 2 * N;
	M* A = new M[N + 1];
	for (int i = 1; i <= N; i++)
		A[i].data = i;
	for (int i = 1; i <= N; i++)
	    cin >> A[i].score;
	for (int i = 1; i <= N; i++)
		cin >> A[i].Mus;
    quickSort(A, 1, N);
	//for (int i = 1; i <= N; i++)
		//cout << A[i].score << " ";
	for (int i = 0; i < R; i++)
	{
		for (int i = 1; i <= N; i += 2)
			if (A[i].Mus > A[i + 1].Mus)
				A[i].score += 2;
			else if (A[i].Mus < A[i + 1].Mus)
				A[i + 1].score += 2;
			else
			{
				A[i].score++;
				A[i + 1].score++;
			}
		quickSort(A, 1, N);
		/*for (int i = 1; i <= N; i++)
			cout << A[i].score << " ";
		cout << endl;*/
	}
	for (int i = 1; i <= N; i++)
		printf("%d ",A[i].data);
	return 0;
}