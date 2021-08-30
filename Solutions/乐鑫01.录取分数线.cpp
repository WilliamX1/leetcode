class Solution {
public:
    double getAdmissionLine(int k, vector<double>& scores) {
        nth_element(scores.begin(), scores.begin() + k - 1, scores.end(), greater<double>());
        return scores[k - 1];
    }
};