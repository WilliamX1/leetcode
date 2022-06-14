class Solution
{
  public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        unordered_map<string, string> copy;
        for (string &word : words)
        {
            string ori = word;
            sort(word.begin(), word.end());
            if (!copy.count(word))
                copy[word] = ori;
        };

        vector<string> ans;
        ans.push_back(copy[words[0]]);
        int n = words.size();
        for (int i = 1; i < n; ++i)
            if (words[i] != words[i - 1])
                ans.push_back(copy[words[i]]);
        return ans;
    }
};