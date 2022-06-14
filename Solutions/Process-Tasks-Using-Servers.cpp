#include <iostream>
#include <queue>

using namespace std;

class Solution
{
  public:
    struct server
    {
        /* data */
        int weight; // 权重
        int idx;    // 下标
        int time;   // 恢复时间
        server(){};
        server(int w, int i) : weight(w), idx(i), time(-1){};
    };
    struct cmp_wait
    {
        bool operator()(server a, server b)
        {
            if (a.weight == b.weight)
            {
                if (a.idx > b.idx)
                    return true;
                else
                    return false;
            }
            else
            {
                if (a.weight > b.weight)
                    return true;
                else
                    return false;
            }
        }
    };
    struct cmp_work
    {
        bool operator()(server a, server b)
        {
            if (a.time > b.time)
                return true;
            else
                return false;
        }
    };
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        priority_queue<server, vector<server>, cmp_wait> waitheap;
        /* 构造小根堆*/
        int n = servers.size(), m = tasks.size();
        for (int i = 0; i < n; i++)
        {
            waitheap.push(server(servers[i], i));
        };

        priority_queue<server, vector<server>, cmp_work> workheap;
        /* 模拟 */
        vector<int> ans(m, 0);
        int time = 0, i = 0;
        while (i < m)
        {
            /* 将完成工作的机器恢复到空闲状态 */
            while (!workheap.empty())
            {
                if (workheap.top().time <= time)
                {
                    waitheap.push(workheap.top());
                    workheap.pop();
                }
                else
                    break;
            };
            /*选择工作机器并加入到工作队列中*/
            while (!waitheap.empty() && time >= i && i < m)
            {
                server cur = waitheap.top();
                waitheap.pop();
                ans[i] = cur.idx;
                cur.time = time + tasks[i];
                workheap.push(cur);
                i++;
            }
            if (waitheap.empty())
            {
                time = workheap.top().time;
            }
            else
                time++;
        };
        return ans;
    }
};

int main()
{
    vector<int> servers = {3, 3, 2}, tasks = {1, 2, 3, 2, 1, 2};
    Solution S;
    S.assignTasks(servers, tasks);
    return 0;
}