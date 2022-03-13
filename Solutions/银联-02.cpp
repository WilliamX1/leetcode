class DiscountSystem {
public:
    const int N = 1000;
    vector<vector<int>> con;
    unordered_map<int, vector<int>> activity;

    DiscountSystem() {
        con = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    }
    
    void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
        activity[actId] = {priceLimit, discount, number, userLimit};
    }
    
    void removeActivity(int actId) {
        activity[actId][2] = 0;
    };
    
    int consume(int userId, int cost) {
        int activityId = -1;
        for (auto iter : activity) {
            int actId = iter.first;
            vector<int> info = iter.second;
            if (cost >= info[0] && con[userId][actId] < info[3] && info[2] > 0 && (activityId == -1 || activity[activityId][1] < info[1] || (activity[activityId][1] == info[1] && actId < activityId)))
                activityId = actId;
        };
        if (activityId == -1) return cost;
        else {
            con[userId][activityId]++;
            activity[activityId][2]--;
            return cost - activity[activityId][1];
        };
    }
};

/**
 * Your DiscountSystem object will be instantiated and called as such:
 * DiscountSystem* obj = new DiscountSystem();
 * obj->addActivity(actId,priceLimit,discount,number,userLimit);
 * obj->removeActivity(actId);
 * int param_3 = obj->consume(userId,cost);
 */