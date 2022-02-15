#include <vector>
#include <queue>
#include <iostream>

using LL = long long;
using namespace std;

class Solution {
public:
    struct cmp_sell {
        bool operator() (vector<int> a, vector<int> b) {
            return a[0] > b[0];
        };
    };
    struct cmp_buy {
        bool operator() (vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
    };
    int getNumberOfBacklogOrders(vector< vector<int> >& orders) {
        priority_queue< vector<int>, vector< vector<int> >, cmp_sell > sell;
        priority_queue< vector<int>, vector< vector<int> >, cmp_buy > buy;
        int len = orders.size(), mod = 1e9 + 7;
        for (int i = 0; i < len; i++) {
            if (orders[i][2] == 0) { // buy
                while (!sell.empty() && sell.top()[0] <= orders[i][0]) {
                    vector<int> v = sell.top(); sell.pop();
                    if (v[1] == orders[i][1]) {
                        orders[i][1] = 0;
                        break;
                    } else if (v[1] > orders[i][1]) {
                        v[1] -= orders[i][1];
                        sell.push(v);
                        orders[i][1] = 0;
                        break;
                    } else {
                        orders[i][1] -= v[1];
                    };
                };
                if (orders[i][1]) buy.push(orders[i]);
            } else { // sell
                while (!buy.empty() && buy.top()[0] >= orders[i][0]) {
                    vector<int> v = buy.top(); buy.pop();
                    if (v[1] == orders[i][1]) {
                        orders[i][1] = 0;
                        break;
                    } else if (v[1] > orders[i][1]) {
                        v[1] -= orders[i][1];
                        buy.push(v);
                        orders[i][1] = 0;
                        break;
                    } else {
                        orders[i][1] -= v[1];
                    };
                };
                if (orders[i][1]) sell.push(orders[i]);
            };
        };
        LL ans = 0;
        while (!sell.empty()) {
            ans = (ans + (LL) sell.top()[1]) % mod;
            sell.pop();
        };
        while (!buy.empty()) {
            ans = (ans + (LL) buy.top()[1]) % mod;
            buy.pop();
        };
        return ans;
    }
};