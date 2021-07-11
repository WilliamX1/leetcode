#include <bits/stdc++.h>

using namespace std;

/* 未完成 */
class Solution {
public:
    int colorTheGrid(int m, int n) {
        int64_t mod = 1e9 + 7;
        if (m == 1) {
            int64_t a = 3; // 1 2 3
            while (--n > 0) a = (a * 2) % mod;
            return a;
        };

        if (m == 2) {
            int64_t ab = 6; // 12 21 13 31 23 32
            while (--n > 0) ab = (ab * 3) % mod;
            return ab;
        };

        if (m == 3) {
            int64_t abc = 3 * 2 * 1; // 123 132 213 231 312 321
            int64_t aba = 3 * 2; // 121 131 212 232 313 323
            int64_t tmp_abc = abc, tmp_aba = aba;
            while (--n > 0) {
                abc = (2 * tmp_abc + 2 * tmp_aba) % mod;
                aba = (2 * tmp_abc + 3 * tmp_aba) % mod;
                tmp_abc = abc, tmp_aba = aba;
            };
            return (abc + abc) % mod;
        };

        if (m == 4) {
            int64_t abcd = 4 * 3 * 2 * 1;
            int64_t abad = 4 * 3 * 3, abcb = 4 * 3 * 3;
            int64_t abab = 4 * 3;
            int64_t tmp_abcd = abcd, tmp_abad = abad, tmp_abcb = abcb, tmp_abab = abab;
            while (--n > 0) {
                abcd = (9 * tmp_abcd + 8 * tmp_abad + 8 * tmp_abcb + 4 * tmp_abab) % mod;
                abad = abcb = (8 * tmp_abcd + 11 * tmp_abad + 8 * tmp_abcb + 5 * tmp_abab) % mod;
                abab = (4 * tmp_abcd + 5 * tmp_abad + 5 * tmp_abcb) % mod;
                tmp_abcd = abcd, tmp_abad = tmp_abcb = abad = abcb, tmp_abab = abab;
            };
            return (abcd + abad + abcb + abab) % mod;
        };
        return -1;
    }
};