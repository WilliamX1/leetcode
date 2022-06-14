#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class MovieRentingSystem
{
  public:
    const int N = 3 * 1e5;
    struct node
    {
        int shop;
        int movie;
        int price;
        node(int shop, int movie, int price) : shop(shop), movie(movie), price(price){};
        bool operator<(const node &a) const
        {
            if (this->price != a.price)
                return this->price < a.price;
            else if (this->shop != a.shop)
                return this->shop < a.shop;
            else
                return this->movie < a.movie;
        };
    };
    vector<map<node, int, less<node>>> movie2shop;
    vector<map<node, int, less<node>>> shop2movie;
    map<int, map<int, int>> movieshop2price;
    map<node, node, less<node>> rentmovies;

    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        movie2shop = vector<map<node, int, less<node>>>(N + 1);
        shop2movie = vector<map<node, int, less<node>>>(N + 1);

        for (const vector<int> &entry : entries)
        {
            int shop = entry[0], movie = entry[1], price = entry[2];
            movie2shop[movie].insert(pair<node, int>(node(shop, movie, price), shop));
            shop2movie[shop].insert(pair<node, int>(node(shop, movie, price), movie));
            movieshop2price[movie][shop] = price;
        };
    }

    vector<int> search(int movie)
    {
        map<node, int, less<node>> m = movie2shop[movie];
        vector<int> answer;
        for (map<node, int, less<node>>::iterator iter = m.begin(); iter != m.end() && answer.size() < 5; ++iter)
            answer.push_back(iter->second);
        return answer;
    }

    void rent(int shop, int movie)
    {
        node n = node(shop, movie, movieshop2price[movie][shop]);
        shop2movie[shop].erase(shop2movie[shop].find(n));
        movie2shop[movie].erase(movie2shop[movie].find(n));
        rentmovies.insert(pair<node, node>(n, n));
        return;
    }

    void drop(int shop, int movie)
    {
        node n = node(shop, movie, movieshop2price[movie][shop]);
        shop2movie[shop].insert(pair<node, int>(n, movie));
        movie2shop[movie].insert(pair<node, int>(n, shop));
        rentmovies.erase(rentmovies.find(n));
        return;
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> answer;
        for (map<node, node, less<node>>::iterator iter = rentmovies.begin();
             iter != rentmovies.end() && answer.size() < 5; ++iter)
        {
            node n = iter->first;
            answer.push_back({n.shop, n.movie});
        };
        return answer;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */