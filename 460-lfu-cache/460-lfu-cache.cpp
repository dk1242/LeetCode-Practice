class LFUCache {
public:
    list<pair<int, int>>l;
    unordered_map<int,pair<int, int>> mp; // key-> list
    unordered_map<int, pair<int, int>>m; // key -> {val, freq}
    unordered_map<int,list<int>> freq; // freq-> list
    int minFreq=0, size, maxSize;
    LFUCache(int capacity) {
        minFreq=0;
        size=0;
        maxSize=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        freq[m[key].second].remove(key);
        m[key].second++;
        freq[m[key].second].push_front(key);
        if(freq[minFreq].size()==0 ) 
              minFreq++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(maxSize<=0) return;
        int stored=get(key);
        if(stored!=-1){
            m[key].first=value;
            return;
        }
        if(size>=maxSize){
            m.erase(freq[minFreq].back());
            mp.erase(freq[minFreq].back());
            freq[minFreq].pop_back();
            size--;
        }
        m[key]={value, 1};
        freq[1].push_front(key);
        mp[key]={key, value};
        minFreq=1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */