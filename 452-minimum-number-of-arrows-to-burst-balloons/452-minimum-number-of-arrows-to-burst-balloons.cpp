class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& point) {
        int count = 0, minEnd = INT_MAX;
        vector<pair<int, int>>points;
        for(int i=0;i<point.size();i++){
            points.push_back(make_pair(point[i][0], point[i][1]));
        }
        sort(points.begin(), points.end());
        for(auto& p: points) {
            if(p.first > minEnd) {count++; minEnd = p.second;}
            else minEnd = min(minEnd, p.second);
        }
        return count+1;
    }
};