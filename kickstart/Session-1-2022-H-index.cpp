#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
    int len = citations_per_paper.size();
    vector<int> h_index;
    // TODO: Calculate and return h-index score for each paper.
    vector<int> cnt(1e5 + 1, 0);
    int cur = 0, tot = 0;
    for (auto &paper : citations_per_paper) {
        cnt[paper]++;
        if (paper >= cur) tot++;

        while (tot - cnt[cur] > cur) {
            tot -= cnt[cur];
            cur++;
        };

        h_index.push_back(cur);
    };
    return h_index;
}

int main() {
  int tests;
  cin >> tests;
  for (int test_case = 1; test_case <= tests; test_case++) {
    // Get number of papers for this test case
    int paper_count;
    cin >> paper_count;
    // Get number of citations for each paper
    vector<int> citations(paper_count);
    for (int i = 0; i < paper_count; i++) {
      cin >> citations[i];
    }
    vector<int> answer = GetHIndexScore(citations);
    cout << "Case #" << test_case << ": ";
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
