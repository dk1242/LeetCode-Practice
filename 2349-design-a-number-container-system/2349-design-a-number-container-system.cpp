class NumberContainers {
public:
    unordered_map<int, int>ind2num;
    unordered_map<int, set<int>>num2ind;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        
        int prevnum=ind2num[index];
        ind2num[index]=number;
        // cout<<prevnum;
        num2ind[prevnum].erase(index);
        num2ind[number].insert(index);
    }
    
    int find(int number) {
        if(num2ind.find(number)==num2ind.end() || num2ind[number].size()==0)
            return -1;
        // set st=num2ind[number];
        // // for(auto it:st)
        // //     cout<<it<<" ";
        // // cout<<"\n";
        // int ans=*st.begin();
        return *num2ind[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */