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
    char LastChar, Match; // LastCharΪ����ķ��ţ�MatchΪջ���ķ���

    while (LastChar = GetNextSymbol())
    { //���ļ��ж������ţ�ֱ���ļ�����
        switch (LastChar)
        {
        case '(':
        case '[':
        case '{': //����3�п�����֮һ�����ջ
            node.Token = LastChar;
            node.TheLine = currentLine;
            st.push(node);
            break;
        case ')':
        case ']':
        case '}':
            if (st.isEmpty())
            { //�޶�Ӧ��������
                ++Errors;
                cout << "�ڵ�" << currentLine << "��һ�������" << LastChar << endl;
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
    { //ջ�еĿ����ž�û������������
        ++Errors;
        node = st.pop();
        cout << "��" << node.TheLine << "�еķ���" << node.Token << "��ƥ��\n";
    }
    return Errors;
}
bool balance::CheckMatch(char Symb1, char Symb2, int Line1, int Line2)
{
    if (Symb1 == '(' && Symb2 != ')' || Symb1 == '[' && Symb2 != ']' || Symb1 == '}' && Symb2 != '}')
    {
        cout << "���ֵ�" << Line2 << "�ķ���" << Symb2 << "���" << Line1 << "�ķ���" << Symb1 << "��ƥ��\n";
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
        { //������ע��
            ch = NextChar();
            if (ch == '*')
                SkipComment(SlashStar); //����C����ע��
            else if (ch == '/')
                SkipComment(SlashStar); //����C++����ע��
            else
                PutBackChar(ch); //����ע��
        }
        else if (ch == '\\' || ch == '"')
            SkipQuote(ch); //�����ַ��������ַ�������
        else if (ch = '{' || ch == '[' || ch == '(' || ch == ']' || ch == '}')
            return ch;
    }
    return NULL; //�ļ�����
}
char balance::NextChar()
{
    char ch;
    if ((ch = fin.get()) == EOF)
        return NULL; //�ļ��������������NULL;
    if (ch == '\n')
        ++currentLine; //���뻻�з�'\n',�м�������1��
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
            ch = NextChar(); //����ת���ַ�
    }
}
void balance::SkipComment(enum CommentType type)
{
    char ch, flag;

    if (type == SlashSlash)
    { //����//�����
        while ((ch = NextChar()) && (ch != '\n'))
            ; //����������ַ���ֱ������س�
        return;
    }

    //����/*��*/�����
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
