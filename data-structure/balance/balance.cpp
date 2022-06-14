#include "seqStack.h"
#include <iostream>
using namespace std;

balance::balance(const char *s)
{
    fin.open(s);
    if (!fin)
        throw noFile();

    currentLine = 1;
    Errors = 0;
}
int balance::CheckBalance()
{
    struct Symbol node;
    seqStack<Symbol> st;
    char LastChar, Match; // LastChar为读入的符号，Match为栈顶的符号

    while (LastChar = GetNextSymbol())
    { //从文件中读入括号，直到文件结束
        switch (LastChar)
        {
        case '(':
        case '[':
        case '{': //若是3中开括号之一，则进栈
            node.Token = LastChar;
            node.TheLine = currentLine;
            st.push(node);
            break;
        case ')':
        case ']':
        case '}':
            if (st.isEmpty())
            { //无对应的左括号
                ++Errors;
                cout << "在第" << currentLine << "有一个多余的" << LastChar << endl;
            }
            else
            {
                node = st.pop();
                Match = node.Token;
                if (!CheckMatch(Match, LastChar, node.TheLine, currentLine))
                    ++Errors;
            }
            break;
        }
    }
    while (!st.isEmpty())
    { //栈中的开括号均没有遇到闭括号
        ++Errors;
        node = st.pop();
        cout << "第" << node.TheLine << "行的符号" << node.Token << "不匹配\n";
    }
    return Errors;
}
bool balance::CheckMatch(char Symb1, char Symb2, int Line1, int Line2)
{
    if (Symb1 == '(' && Symb2 != ')' || Symb1 == '[' && Symb2 != ']' || Symb1 == '}' && Symb2 != '}')
    {
        cout << "发现第" << Line2 << "的符号" << Symb2 << "与第" << Line1 << "的符号" << Symb1 << "不匹配\n";
        return false;
    }
    else
        return true;
}
char balance::GetNextSymbol()
{
    char ch;
    while (ch == NextChar())
    {
        if (ch == '/')
        { //可能是注释
            ch = NextChar();
            if (ch == '*')
                SkipComment(SlashStar); //处理C风格的注释
            else if (ch == '/')
                SkipComment(SlashStar); //处理C++风格的注释
            else
                PutBackChar(ch); //不是注释
        }
        else if (ch == '\\' || ch == '"')
            SkipQuote(ch); //处理字符常量或字符串常量
        else if (ch = '{' || ch == '[' || ch == '(' || ch == ']' || ch == '}')
            return ch;
    }
    return NULL; //文件结束
}
char balance::NextChar()
{
    char ch;
    if ((ch = fin.get()) == EOF)
        return NULL; //文件读入结束，返回NULL;
    if (ch == '\n')
        ++currentLine; //读入换行符'\n',行计数器加1；
    return ch;
}
void balance::PutBackChar(char ch)
{
    fin.putback(ch);
    if (ch == '\n')
        --currentLine;
}
void balance::SkipQuote(char type)
{
    char ch;
    while ((ch = NextChar()))
    {
        if (ch == type)
            return;
        else if (ch == '\n')
        {
            ++Errors;
            cout << "missing closing quote is line" << currentLine << endl;
            return;
        }
        else if (ch == '\\')
            ch = NextChar(); //跳过转义字符
    }
}
void balance::SkipComment(enum CommentType type)
{
    char ch, flag;

    if (type == SlashSlash)
    { //处理//的情况
        while ((ch = NextChar()) && (ch != '\n'))
            ; //跳过读入的字符，直到读入回车
        return;
    }

    //处理/*…*/的情况
    flag = ' ';
    while ((ch = NextChar()) != NULL)
    {
        if (flag == '*' && ch == '/')
            return;
        flag = ch;
    }
    ++Errors;
    cout << "Comment is unterminated!" << endl;
}
