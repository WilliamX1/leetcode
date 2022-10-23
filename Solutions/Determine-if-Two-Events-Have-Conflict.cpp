class Solution
{
  public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        for (char ch1 = '0'; ch1 <= '9'; ch1++)
            for (char ch2 = '0'; ch2 <= '9'; ch2++)
                for (char ch3 = '0'; ch3 <= '9'; ch3++)
                    for (char ch4 = '0'; ch4 <= '9'; ch4++)
                    {
                        string str;
                        str.push_back(ch1);
                        str.push_back(ch2);
                        str.push_back(':');
                        str.push_back(ch3);
                        str.push_back(ch4);

                        if (event1.front() <= str && str <= event1.back() && event2.front() <= str &&
                            str <= event2.back())
                            return true;
                    };
        return false;
    }
};