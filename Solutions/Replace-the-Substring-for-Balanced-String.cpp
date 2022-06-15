class Solution
{
  public:
    int balancedString(string s)
    {
        int n = s.size(), upper = n >> 2;
        vector<int> Qvec(n + 1, 0), Wvec(n + 1, 0), Evec(n + 1, 0), Rvec(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            Qvec[i] = (i > 0 ? Qvec[i - 1] : 0) + (s[i] == 'Q');
            Wvec[i] = (i > 0 ? Wvec[i - 1] : 0) + (s[i] == 'W');
            Evec[i] = (i > 0 ? Evec[i - 1] : 0) + (s[i] == 'E');
            Rvec[i] = (i > 0 ? Rvec[i - 1] : 0) + (s[i] == 'R');
        };
        Qvec[n] = Qvec[n - 1];
        Wvec[n] = Wvec[n - 1];
        Evec[n] = Evec[n - 1];
        Rvec[n] = Rvec[n - 1];

        int ans = 0x7fffffff;
        for (int i = n; i >= 0; i--)
        {
            int Qcnt = upper - (Qvec[n - 1] - Qvec[i] + (i < n && s[i] == 'Q'));
            int Wcnt = upper - (Wvec[n - 1] - Wvec[i] + (i < n && s[i] == 'W'));
            int Ecnt = upper - (Evec[n - 1] - Evec[i] + (i < n && s[i] == 'E'));
            int Rcnt = upper - (Rvec[n - 1] - Rvec[i] + (i < n && s[i] == 'R'));

            if (Qcnt < 0 || Wcnt < 0 || Ecnt < 0 || Rcnt < 0)
                break;

            int Qidx = min(i, (int)(upper_bound(Qvec.begin(), Qvec.end(), Qcnt) - Qvec.begin()));
            int Widx = min(i, (int)(upper_bound(Wvec.begin(), Wvec.end(), Wcnt) - Wvec.begin()));
            int Eidx = min(i, (int)(upper_bound(Evec.begin(), Evec.end(), Ecnt) - Evec.begin()));
            int Ridx = min(i, (int)(upper_bound(Rvec.begin(), Rvec.end(), Rcnt) - Rvec.begin()));
            int idx = n;
            idx = min(idx, Qidx);
            idx = min(idx, Widx);
            idx = min(idx, Eidx);
            idx = min(idx, Ridx);
            // cout << "cnt: " << Qcnt << ' ' << Wcnt << ' ' << Ecnt << ' ' << Rcnt << endl;
            // cout << "idx: " << Qidx << ' ' << Widx << ' ' << Eidx << ' ' << Ridx << endl;
            ans = min(ans, i - idx);
            // cout << "idx: " << idx << " ans: " << ans << endl;
        };
        return ans;
    }
};