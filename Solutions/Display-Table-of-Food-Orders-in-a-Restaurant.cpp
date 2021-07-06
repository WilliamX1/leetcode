#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {    
        vector<string> food_name; food_name.push_back("Table");

        int len = orders.size();
        unordered_map<string, int> food_to_int; int food_cnt = 1; 
        unordered_map<string, int> table_to_int; int table_cnt = 0;
        
        /* 按照桌号排序 */
        sort(orders.begin(), orders.end(), [](const vector<string>& a, const vector<string>& b) {
            return stoi(a[1]) < stoi(b[1]);
        });
        for (auto order : orders) 
        {
            if (table_to_int.find(order[1]) == table_to_int.end()) {
                table_to_int.insert(make_pair(order[1], table_cnt++));
            };
        };
        /* 按照菜名排序 */
        sort(orders.begin(), orders.end(), [](const vector<string>& a, const vector<string>& b) {
            return a[2] < b[2];
        });
        for (auto order : orders) 
        {
            if (food_to_int.find(order[2]) == food_to_int.end()) {
                food_to_int.insert(make_pair(order[2], food_cnt++));
                food_name.push_back(order[2]);
            };
        };

        vector<vector<string>> ans(table_cnt, vector<string>(food_cnt, "0"));
        int table_num = 0, food_num = 0;
        for (auto order : orders) 
        {
            table_num = table_to_int.find(order[1])->second;
            food_num = food_to_int.find(order[2])->second;
            ans[table_num][0] = order[1];
            ans[table_num][food_num] = to_string(stoi(ans[table_num][food_num]) + 1);
        };
        ans.insert(ans.begin(), food_name);
        return ans;
    }
};