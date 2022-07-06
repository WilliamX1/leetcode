class Solution
{
  public:
    string simplifyPath(string path)
    {
        int next = 0, size = path.size();
        deque<string> ans;
        while (next < size)
        {
            string tmp;
            while (++next < size && path[next] != '/')
            {
                tmp.push_back(path[next]);
            };
            if (tmp.empty() || tmp == "." || tmp == "/")
                continue;
            else if (tmp == "..")
            {
                if (!ans.empty())
                    ans.pop_back();
            }
            else
                ans.push_back(tmp);
        };
        string ret;
        while (!ans.empty())
        {
            ret.push_back('/');
            ret.append(ans.front());
            ans.pop_front();
        };
        if (ret.empty())
            ret.push_back('/');
        return ret;
    }
};