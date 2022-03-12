class LRUCache {
public:
    list<pair<int, int>>l;
    unordered_map<int,list<pair<int, int>>::iterator> mp;
    int size;
    LRUCache(int capacity) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        size=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
                return -1;
        l.splice(l.begin(),l,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            {
                l.splice(l.begin(),l,mp[key]);
                mp[key]->second=value;
                return;
            }
        
        if(l.size()==size)
            {
                auto d_key=l.back().first;
                l.pop_back();
                mp.erase(d_key);
            }
            l.push_front({key,value});
            mp[key]=l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */