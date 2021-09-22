class CQueue {
private:
    stack<int> main_stk, assist_stk;
public:
    CQueue() {
        return;
    }
    
    void appendTail(int value) {
        main_stk.push(value);
    }
    
    int deleteHead() {
        if (main_stk.empty()) return -1;
        while (!main_stk.empty()) {
            assist_stk.push(main_stk.top());
            main_stk.pop();
        };
        int ans = assist_stk.top(); 
        assist_stk.pop();
        while (!assist_stk.empty()) {
            main_stk.push(assist_stk.top());
            assist_stk.pop();
        };
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */