class Solution {
public:
    bool checkColor(vector<vector<int>>& graph, vector<int>&colors, int color, int i){
        if(colors[i]!=0){
            return colors[i]==color;
        }
        colors[i]=color;
        for(auto it:graph[i]){
            if(!checkColor(graph, colors, -color, it)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colors(n, 0);
        for(int i=0;i<n;i++){
            if(colors[i]==0 && !checkColor(graph, colors, 1, i)){
                return false;
            }
        }
        return true;
    }
};