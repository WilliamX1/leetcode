#ifndef balance
#define balance
class balance
{
  private:
    ifstream fin;    //待检查的文件流
    int currentLine; //正在处理行的行号
    int Errors;      //以发现的错误数

    struct Symbol
    {
        char Token;
        int TheLine;
    }; //栈元素类型
    enum CommentType
    {
        SlashSlash,
        SlashStar
    }; // C++注释与C注释

    // CheckBalance用到的工具函数
    bool CheckMatch(char Symb1, char Symb2, int Line1, int Line2);
    char GetNextSymbol();
    void PutBackChar(char ch);
    void SkipComment(enum CommentType type);
    void SkipQuote(char type);
    char NextChar();

  public:
    balance(const char *s);
    int CheckBalance(); //检查fin中的括号是否匹配
    class noFile
    {
    };
};
#endif