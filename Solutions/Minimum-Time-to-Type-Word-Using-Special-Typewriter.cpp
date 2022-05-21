class Solution {
public:
    int minTimeToType(string word) {
        word.insert(word.begin(), 'a');
        int answer = 0;
        for (int i = 1; i < word.size(); i++) {
            answer += min(abs(word[i] - word[i - 1]), 26 - abs(word[i] - word[i - 1])) + 1;
        };
        return answer;
    }
};