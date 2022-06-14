class Solution
{
  public:
    string maximumBinaryString(string binary)
    {
        int zeros = 0, ones = 0, preones = 0;
        while (preones < binary.size() && binary[preones] == '1')
            preones++;
        for (int i = preones; i < binary.size(); i++)
        {
            zeros += binary[i] == '0';
            ones += binary[i] == '1';
        };
        return string(preones, '1') + (zeros > 0 ? string(zeros - 1, '1') + "0" : "") + string(ones, '1');
    }
};