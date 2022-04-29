class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<int, int> counts;
        int answer = 0;
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            switch (croakOfFrogs[i]) {
                case 'c': break;
                case 'r': 
                    if (!counts['c']) return -1;
                    else break;
                case 'o': 
                    if (!counts['c'] || !counts['r']) return -1;
                    else break;
                case 'a': 
                    if (!counts['c'] || !counts['r'] || !counts['o']) return -1;
                    else break;
                case 'k': 
                    if (!counts['c'] || !counts['r'] || !counts['o'] || !counts['a']) return -1;
                    else break;
            }
            counts[croakOfFrogs[i]]++;
            while (counts['c'] && counts['r'] && counts['o'] && counts['a'] && counts['k']) {
                counts['c']--;
                counts['r']--;
                counts['o']--;
                counts['a']--;
                counts['k']--;
            };
            answer = max(answer, counts[croakOfFrogs[i]]);
        };
        return counts['c'] || counts['r'] || counts['o'] || counts['a'] || counts['k'] ? -1 : answer;
    }
};