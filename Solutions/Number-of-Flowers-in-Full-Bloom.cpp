class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        unordered_map<int, int> up_down;
        for (const vector<int>& fl : flowers) {
            int start = fl[0], end = fl[1];
            up_down[start]++;
            up_down[end + 1]--;
        };

        vector<int> pos;
        for (const auto iter : up_down) {
            pos.push_back(iter.first);
        };

        vector<int> copy_persons = persons;
        unordered_map<int, int> tmp_answer;

        sort(pos.begin(), pos.end());
        sort(persons.begin(), persons.end());

        int idx = 0, cnt = 0, n = pos.size();
        for (const int& person : persons) {
            while (idx < n && pos[idx] <= person) {
                cnt += up_down[pos[idx]];
                idx++;
            };
            tmp_answer[person] = cnt;
        };
        vector<int> answer;
        for (const int& person : copy_persons) 
            answer.push_back(tmp_answer[person]);
        return answer;
    }
};