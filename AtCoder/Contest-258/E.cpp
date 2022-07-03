#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int64_t N, Q, X, K, tot = 0, copyX;
    cin >> N >> Q >> X;
    vector<int64_t> nums(N), prefix(N);
    for (int64_t i = 0; i < N; i++)
    {
        cin >> nums[i];
        tot += nums[i];
    };
    copyX = X;

    if (X % tot == 0)
    {
        for (int64_t i = 0; i < Q; i++)
        {
            cin >> K;
            cout << X / tot * N << endl;
        };
    }
    else
    {
        X %= tot;

        prefix[0] = nums[0];
        for (int64_t i = 1; i < N; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        vector<int64_t> startidx2endidx(N);
        for (int64_t i = 0; i < N; i++)
        {
            int64_t it = lower_bound(prefix.begin(), prefix.end(), prefix[i] + X - nums[i]) - prefix.begin();
            // cout << "i: " << i << " it: " << it << endl;
            if (it == N)
                startidx2endidx[i] =
                    lower_bound(prefix.begin(), prefix.end(), X - (tot - prefix[i] + nums[i])) - prefix.begin();
            else
                startidx2endidx[i] = it;
        };
        vector<int64_t> idxlist;
        set<int64_t> s;
        int64_t start = 0, loopidx, loopval, loopcnt;
        while (!s.count(start))
        {
            int64_t end = startidx2endidx[start];
            idxlist.push_back(start);
            s.insert(start);

            start = (end + 1) % N;
            loopval = start;
        };

        // for (int64_t i = 0; i < idxlist.size(); i++)
        //     cout << idxlist[i] << ' ';
        // cout << endl;

        for (int64_t i = 0; i < (int64_t)idxlist.size(); i++)
            if (idxlist[i] == loopval)
                loopidx = i;
        loopcnt = (int64_t)idxlist.size() - loopidx;

        for (int64_t i = 0; i < Q; i++)
        {
            cin >> K;
            int64_t start, end;
            if (K - 1 <= loopidx)
            {
                start = idxlist[K - 1];
                end = startidx2endidx[start];
            }
            else
            {
                // cout << "K: " << K << " loopidx: " << loopidx << " loopcnt: " << loopcnt << endl;
                K -= loopidx;
                K = (K - 1) % loopcnt + loopidx;
                // cout << "after: K: " << K << endl;
                start = idxlist[K];
                end = startidx2endidx[start];
            };

            // cout << "start: " << start << " end: " << end << endl;
            if (end >= start)
            {
                int64_t base = copyX - (prefix[end] - prefix[start] + nums[start]);
                // cout << "base: " << base << endl;
                if (base > 0)
                    base = (base - 1) / tot + 1;
                else
                    base = 0;
                cout << end - start + 1 + base * N << endl;
            }
            else
            {
                int64_t base = copyX - (tot - (prefix[start - 1] - prefix[end]));

                if (base > 0)
                    base = (base - 1) / tot + 1;
                else
                    base = 0;
                cout << N - start + end + 1 + base * N << endl;
            };
        };
    };
    return 0;
}