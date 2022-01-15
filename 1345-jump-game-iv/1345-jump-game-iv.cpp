class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool>visited(n, false);
        visited[0]=true;
        queue<int>q;
        q.push(0);
        int step=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int front=q.front();
                q.pop();
                if (front == n - 1) return step;
                vector<int>&next=mp[arr[front]];
                next.push_back(front+1);
                next.push_back(front-1);
                for(int j:next){
                    if(j>=0 && j<n && !visited[j]){
                        visited[j]=true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            step++;
        }
        return step;
    }
};