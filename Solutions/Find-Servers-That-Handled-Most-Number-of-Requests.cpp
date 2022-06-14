#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
  public:
    struct node
    {
        int ending_time;
        int server;
        node(){};
        node(int e, int s) : ending_time(e), server(s){};
        const bool operator<(const node &a) const
        {
            return this->ending_time > a.ending_time;
        };
    };
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        vector<int> count(k, 0);
        map<int, bool> free;
        for (int i = 0; i < k; i++)
            free.insert(pair<int, bool>(i, true));
        priority_queue<node, vector<node>, less<node>> ongoing;
        for (int i = 0; i < arrival.size(); i++)
        {
            while (!ongoing.empty() && ongoing.top().ending_time <= arrival[i])
            {
                node n = ongoing.top();
                ongoing.pop();

                free.insert(pair<int, bool>(n.server, true));
            };

            if (free.empty())
                continue;

            map<int, bool>::iterator final = free.lower_bound(i % k);
            if (final == free.end())
                final = free.begin();

            count[final->first]++;
            ongoing.push(node(arrival[i] + load[i], final->first));
            free.erase(final);
        };

        vector<int> ans;
        int _max = 0;
        for (int i = 0; i < k; i++)
        {
            if (count[i] > _max)
            {
                _max = count[i];
                ans.clear();
                ans.push_back(i);
            }
            else if (count[i] == _max)
            {
                ans.push_back(i);
            }
            else
            {
            };
        };
        return ans;
    }
};