#include <iostream>
#include <vector>

using namespace std;

const int N = 4e7 + 1;
int n, k;
vector<int> a(N + 1, 0);
void read_input_data() {
    int m;
    // n = 5; k = 5; m = 3;
    // a[1] = 2; a[2] = 3; a[3] = 5, a[4] = 1, a[5] = 4;
    // n = 5; k = 4; m = 1;
    // a[1] = 1919810; 
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    unsigned int z = a[m];
    for (int i = m + 1; i <= n; i++) {
        z ^= z << 13;
        z ^= z >> 17;
        z ^= z << 5;
        a[i] = z & 0x7fffffff;
    }
};

int partition(vector<int>& v, int left_idx, int right_idx) {
    int x = rand() % (right_idx - left_idx + 1) + left_idx;
    swap(v[x], v[right_idx]);
    
    int ele = v[right_idx];

    int idx = left_idx - 1;
    for (int i = left_idx; i < right_idx; i++)
        if (v[i] < ele) swap(v[++idx], v[i]);
    swap(v[++idx], v[right_idx]);
    return idx;
}
int get_nthelement(vector<int>& v, const int k, int left_idx, int right_idx) {
    int q = partition(v, left_idx, right_idx);
    if (q == k) return v[q];
    else return q < k ? get_nthelement(v, k, q + 1, right_idx) : get_nthelement(v, k, left_idx, q - 1);
}

int main()
{
    read_input_data();
    int ANS = get_nthelement(a, k, 1, n);
    std::cout << get_nthelement(a, k, 1, n) << std::endl;
    return 0;
}