class LRUCache
{
  public:
    unordered_map<int, int> key2value, key2count;

    deque<int> que;

    int _capacity, _size;

    LRUCache(int capacity)
    {
        _capacity = capacity;
        _size = 0;
    }

    int get(int key)
    {
        if (!key2count[key])
            return -1;
        else
        {
            que.push_back(key);
            key2count[key]++;
            return key2value[key];
        };
    }

    void put(int key, int value)
    {
        _size += !key2count[key];
        key2value[key] = value;
        key2count[key]++;
        que.push_back(key);

        while (_size > _capacity)
        {
            int val = que.front();
            que.pop_front();

            key2count[val]--;
            if (!key2count[val])
                _size--;
        };
    };
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */