class Solution
{
  public:
    bool checkString(string s)
    {
        s = 'a' + s + 'b';
        return s.rfind('a') < s.find('b');
    }
};