class Solution
{
  public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> v = {".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
                            ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
                            "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

        set<string> s;
        for (const string &w : words)
        {
            string c;
            for (const char &ch : w)
            {
                c += v[ch - 'a'];
            };
            s.insert(c);
        };
        return s.size();
    }
};