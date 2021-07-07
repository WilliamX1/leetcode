class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int len = dist.size();
        vector<int> time(len);
        for (int i = 0; i < len; i++)
            time[i] = 1 + (dist[i] - 1) / speed[i];

        sort(time.begin(), time.end(), less<int>());

        for (int i = 0; i < len; i++)
            if (i >= time[i]) return i;
        return len;
    }
};