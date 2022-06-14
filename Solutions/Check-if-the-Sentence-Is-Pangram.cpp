#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool checkIfPangram(string sentence)
    {
        set<char> _set;
        int _len = sentence.length();
        while (_len--)
            _set.insert(sentence[_len]);
        return _set.size() == 26;
    }
};

int main()
{

    return 0;
}