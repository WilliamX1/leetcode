#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>

using namespace std;

set<char> color2vec(const char &ch)
{
    switch (ch)
    {
    case 'U':
        return {};
    case 'R':
        return {'R'};
    case 'Y':
        return {'Y'};
    case 'B':
        return {'B'};
    case 'O':
        return {'R', 'Y'};
    case 'P':
        return {'R', 'B'};
    case 'G':
        return {'B', 'Y'};
    case 'A':
        return {'R', 'B', 'Y'};
    };
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int N;
        cin >> N;
        string str;
        cin >> str;

        int ans = 0;

        vector<set<char>> targets(N);
        for (int j = 0; j < N; j++)
            targets[j] = color2vec(str[j]);

        vector<set<char>> colors(N);
        for (int j = 0; j < N; j++)
            for (const char &ch : targets[j])
                if (!colors[j].count(ch))
                {
                    ans++;
                    for (int k = j; k < N; k++)
                        if (targets[k].count(ch) && !colors[k].count(ch))
                            colors[k].insert(ch);
                        else
                            break;
                };
        printf("Case #%d: %d\n", i, ans);
    };
    return 0;
}