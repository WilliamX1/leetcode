class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end(), less<int>());
        unordered_map<int, int> counts;
        for (const int& c : changed) 
            counts[c]++;
        vector<int> answer;
        for (const int& c : changed) {
            if (counts[c]) {
                answer.push_back(c);
                counts[c]--;
                if (!counts[c << 1]) return vector<int>();
                else counts[c << 1]--;
            };
        };
        return answer;
    }
};