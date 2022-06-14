#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Encrypter
{
  public:
    const int N = 100;
    unordered_map<char, string> key2value;
    unordered_map<string, vector<char>> value2key;
    // vector<unordered_map<string, bool>> dict;
    // vector<unordered_map<string, bool>> prefix;
    unordered_map<string, int> count;

    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary)
    {
        // dict = vector<unordered_map<string, bool>>(N + 1);
        // prefix = vector<unordered_map<string, bool>>(N + 1);

        int n = keys.size();
        for (int i = 0; i < n; i++)
        {
            key2value[keys[i]] = values[i];
            value2key[values[i]].push_back(keys[i]);
        };
        // for (const string& d : dictionary) {
        //     int len = d.size();
        //     dict[len][d] = true;
        //     string tmp;
        //     for (const char& ch : d) {
        //         tmp += ch;
        //         prefix[len][tmp] = true;
        //     };
        // };
        for (const string &d : dictionary)
        {
            count[encrypt(d)]++;
        };
        return;
    };

    string encrypt(string word1)
    {
        string ans(word1.size() * 2, ' ');
        for (int i = 0; i < word1.size(); i++)
        {
            string tmp = key2value[word1[i]];
            ans[i << 1] = tmp[0];
            ans[(i << 1) + 1] = tmp[1];
        };
        return ans;
    };

    // int _decrypt(const string& ori, const int& n, const int& index, string& now) {
    //     if (index == n && dict[now]) return 1;

    //     string value(ori, index, 2);

    //     vector<char> v = value2key[value];
    //     int ans = 0;
    //     now.push_back(' ');
    //     for (const char& ch : v) {
    //         now.back() = ch;
    //         if (prefix[now])
    //             ans += _decrypt(ori, n, index + 2, now);
    //     };
    //     now.pop_back();
    //     return ans;
    // };

    // struct node {
    //     string now;
    //     int index;
    //     node() {};
    //     node(string now, int index) : now(now), index(index) {};
    // };

    int decrypt(string word2)
    {
        return count[word2];
        // string str = "";
        // return _decrypt(word2, word2.size(), 0, str);
        // int ans = 0, n = word2.size(), len = n >> 1;
        // queue<node> que;
        // que.push(node("", 0));
        // while (!que.empty()) {
        //     node t = que.front();
        //     que.pop();

        //     if (t.index == n) {
        //         ans += dict[len][t.now];
        //         continue;
        //     };

        //     string value(word2, t.index, 2), now = t.now;
        //     vector<char> v = value2key[value];
        //     now += ' ';
        //     for (const char& ch : v) {
        //         now[now.size() - 1] = ch;
        //         if (prefix[len][now])
        //             que.push(node(now, t.index + 2));
        //     };
        // };
        // return ans;
    };
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */