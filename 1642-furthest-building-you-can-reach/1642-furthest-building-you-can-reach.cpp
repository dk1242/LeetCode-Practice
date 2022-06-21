class Solution {
public:
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        int n=height.size();
        // vector<int>res;
        priority_queue<int>pq;
        for(int i=1;i<n;i++){
            int d=height[i]-height[i-1];
            if(d>0)
                pq.push(-d);
            if(pq.size()>ladders){
                bricks+=pq.top();
                pq.pop();
            }
            if(bricks<0)
                return i-1;
        }
        return n-1;
    }
};