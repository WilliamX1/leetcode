class CombinationIterator {
public:
    vector<string> v;
    int index, n;
    CombinationIterator(string characters, int combinationLength) {
        generate(characters, characters.size(), combinationLength, 0, "");
        sort(v.begin(), v.end(), less<string>());
        n = v.size();
        index = 0;
    };

    void generate(const string& characters, const int& n, const int& combinationLength, const int& curIndex, string curStr) {
        if (combinationLength == curStr.length()) {
            v.push_back(curStr);
            return;
        };

        if (curIndex == n) return;

        generate(characters, n, combinationLength, curIndex + 1, curStr);

        curStr.push_back(characters[curIndex]);
        generate(characters, n, combinationLength, curIndex + 1, curStr);
        
        return;
    }
    
    string next() {
        return v[index++];
    }
    
    bool hasNext() {
        return index < n;
    };
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */