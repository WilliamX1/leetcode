class Solution {
public:
    struct arrival_cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
    };
    struct leaving_cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        };
    };
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int, vector<int>, greater<int>> free_chairs;
        priority_queue<vector<int>, vector<vector<int>>, arrival_cmp> not_arrive;
        priority_queue<vector<int>, vector<vector<int>>, leaving_cmp> prepare_leaving;
        int n = times.size();
        for (int i = 0; i < n; i++) {
            free_chairs.push(i);
            times[i].push_back(i);
            not_arrive.push(times[i]);
        };
        for (int i = n; i < 2 * n; i++)
            free_chairs.push(i);
        while (true) {    
            while (!prepare_leaving.empty() && prepare_leaving.top()[1] <= not_arrive.top()[0]) {                    
                free_chairs.push(prepare_leaving.top()[3]);
                prepare_leaving.pop();
            };

            vector<int> top = not_arrive.top();
            not_arrive.pop();
            int free_chair = free_chairs.top();
            free_chairs.pop();
            top.push_back(free_chair);
            prepare_leaving.push(top);

            if (top[2] == targetFriend) return free_chair;
        };
        return -1;
    }
};