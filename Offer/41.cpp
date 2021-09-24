class MedianFinder {
private:
    vector<int> arr;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        arr = vector<int>();
    }
    
    void addNum(int num) {
        auto iter = lower_bound(arr.begin(), arr.end(), num);
        arr.insert(iter, num);
    }
    
    double findMedian() {
        int len = arr.size();
        return len & 1 ? double(arr[len >> 1]) : (double(arr[(len >> 1) - 1]) + double(arr[len >> 1])) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */