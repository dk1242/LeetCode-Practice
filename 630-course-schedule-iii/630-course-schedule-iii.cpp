class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int>pq;
        int total=0;
        for(auto &c:courses){
            int dur=c[0], end=c[1];
            if(total+dur<=end){
                total+=dur;
                pq.push(dur);
            }else if(pq.size()>0 && pq.top()>dur){
                total+=dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};