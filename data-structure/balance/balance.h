#ifndef balance
#define balance
class balance
{
  private:
    ifstream fin;    //�������ļ���
    int currentLine; //���ڴ����е��к�
    int Errors;      //�Է��ֵĴ�����

    struct Symbol
    {
        char Token;
        int TheLine;
    }; //ջԪ������
    enum CommentType
    {
        SlashSlash,
        SlashStar
    }; // C++ע����Cע��

    // CheckBalance�õ��Ĺ��ߺ���
    bool CheckMatch(char Symb1, char Symb2, int Line1, int Line2);
    char GetNextSymbol();
    void PutBackChar(char ch);
    void SkipComment(enum CommentType type);
    void SkipQuote(char type);
    char NextChar();

  public:
    balance(const char *s);
    int CheckBalance(); //���fin�е������Ƿ�ƥ��
    class noFile
    {
    };
};
#endif