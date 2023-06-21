# include <iostream>
# include <stdio.h>
# include <vector>

using namespace std;

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n, m; scanf("%d %d", &n, &m);

    struct node {
        int val;
        int idx;
        node() {};
        node(int _val, int _idx) : val(_val), idx(_idx) {};
    };

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    };

    vector<vector<node>> v;

    int start = -1;

    vector<node> tmp;
    for (int i = 0; i < n; i++) {
        if (start == -1 || start == numbers[i]) {
            start = numbers[i];
            tmp.push_back(node(numbers[i], i));
        } else {
            v.push_back(tmp);
            tmp.clear();
            start = numbers[i];
            tmp.push_back(node(numbers[i], i));
        };
    };
    if (tmp.size()) v.push_back(tmp);

    vector<int> index(v.size(), 0);
    bool flag = false;

    do {
        flag = false;
        for (int i = 0; i < v.size(); i++) {
            if (index[i] < v[i].size()) {
                flag = true;
                printf("%d ", v[i][index[i]].idx + 1);

                index[i]++;
            };
        };
        for (int i = 0; i < v.size(); i++) {
            if (index[i] == v[i].size()) {
                int up = i - 1;
                while (up >= 0 && index[up] >= v[up].size()) up--;
                int down = i + 1;
                while (down < v.size() && index[down] >= v[down].size()) down++;

                if (up >= 0 && down < v.size() && v[up].back().val == v[down].back().val) {
                    v[up].insert(v[up].end(), v[down].begin() + index[down], v[down].end());
                    index[down] = v[down].size() + 1;
                };

                index[i]++;
            };
        };
        if (flag) printf("\n");
    } while (flag);
    
    return 0;
}