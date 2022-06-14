class TextEditor
{
    struct node
    {
        char ch;
        node *prev;
        node *next;
        node(char ch = '|', node *prev = NULL, node *next = NULL) : ch(ch), prev(prev), next(next){};
    };
    node *add(node *cur, char ch)
    {
        node *orinext = cur->next;
        cur->next = new node(ch, cur, orinext);
        orinext->prev = cur->next;
        return cur->next;
    }
    node *del(node *cur)
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        return cur->prev;
    };
    node *left(node *cur)
    {
        return cur == head ? cur : cur->prev;
    };
    node *right(node *cur)
    {
        return cur->next == head ? cur : cur->next;
    };
    node *head;

  public:
    node *cursor = NULL;

    TextEditor()
    {
        head = new node('|');
        head->next = head->prev = head;
        cursor = head;
    }

    void addText(string text)
    {
        for (char ch : text)
            cursor = add(cursor, ch);
    }

    int deleteText(int k)
    {
        int ans = 0;
        while (cursor != head && ans < k)
        {
            cursor = del(cursor);
            ans++;
        };
        return ans;
    }

    string cursorLeft(int k)
    {
        string ans = "";
        while (cursor != head && k-- > 0)
            cursor = left(cursor);
        node *tmp = cursor;
        int cnt = 10;
        while (tmp != head && cnt-- > 0)
        {
            ans.push_back(tmp->ch);
            tmp = left(tmp);
        };
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string cursorRight(int k)
    {
        string ans = "";
        while (k-- > 0)
            cursor = right(cursor);
        node *tmp = cursor;
        int cnt = 10;
        while (tmp != head && cnt-- > 0)
        {
            ans.push_back(tmp->ch);
            tmp = left(tmp);
        };
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */