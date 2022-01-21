#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int t; cin >> t;

    while(t--)
    {
        deque<int> v;
        int n; cin >> n;
        while(n--)
        {
            int type, val;
            cin >> type >> val;
            if (type == 1)
                v.push_back(val);
            else if (type == 2)
                if (val == 0)
                    v.pop_front();
                else if (val == 1)
                    v.pop_back();
        }
        if (v.empty()) cout << "NULL\n";
        else
        {
            while(!v.empty())
            {
                cout << v.front() << " ";
                v.pop_front();
            }
            cout << endl;
        }
    }
    return 0;
}
