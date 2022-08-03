class MyCalendar {
public:
    vector<pair<int, int>>vp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(vp.size()==0){
            vp.push_back({start, end});
            return true;
        }
        for(auto it:vp){
            if(max(it.first, start)<min(it.second, end)){
                return false;
            }
        }
        vp.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */