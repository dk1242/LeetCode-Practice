class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        priority_queue<long long>pq;
        long long sum=0;
        for(int i=0;i<n;i++){
            pq.push(target[i]);
            sum+=target[i];
        }
        while(pq.size() && pq.top()!=1){
            long long num=pq.top();
            pq.pop();
            sum-=num;
            if(num<=sum || sum<1)
                return false;
            num%=sum;
            sum+=num;
            pq.push(num ? num:sum);
        }
        return true;
    }
};