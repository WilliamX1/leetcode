class FoodRatings
{
  public:
    unordered_map<string, int> trueRating;
    unordered_map<string, string> food2cuisine;
    struct node
    {
        string foodname;
        int rating;
        node(){};
        node(string f, int r) : foodname(f), rating(r){};
        const bool operator>(const node &a) const
        {
            return rating == a.rating ? foodname > a.foodname : rating < a.rating;
        };
    };

    unordered_map<string, priority_queue<node, vector<node>, greater<node>>> umap;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            trueRating[foods[i]] = ratings[i];
            umap[cuisines[i]].push(node(foods[i], ratings[i]));

            food2cuisine[foods[i]] = cuisines[i];
        };
    }

    void changeRating(string food, int newRating)
    {
        trueRating[food] = newRating;
        umap[food2cuisine[food]].push(node(food, newRating));
    }

    string highestRated(string cuisine)
    {
        priority_queue<node, vector<node>, greater<node>> &pque = umap[cuisine];
        while (!pque.empty())
        {
            node t = pque.top();
            if (trueRating[t.foodname] == t.rating)
                return t.foodname;
            else
                pque.pop();
        };
        return "";
    };
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */