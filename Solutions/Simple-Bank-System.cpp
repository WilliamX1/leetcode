class Bank {
public:
    vector<long long> blc;
    int count;
    Bank(vector<long long>& balance) {
        this->blc = balance;
        count = balance.size();
    };
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > count || account2 > count) return false;
        else if (blc[account1 - 1] >= money) {
            blc[account1 - 1] -= money;
            blc[account2 - 1] += money;
            return true;
        } else return false;
    }
    
    bool deposit(int account, long long money) {
        if (account > count) return false;
        else {
            blc[account - 1] += money;
            return true;
        };
    }
    
    bool withdraw(int account, long long money) {
        if (account > count) return false;
        else if (blc[account - 1] >= money) {
            blc[account - 1] -= money;
            return true;
        } else return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(blc);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */