class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftMin(n), rightMax(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftMin[i]=0;
            }else{
                leftMin[i]=st.top()+1;
            }
            st.push(i);
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<leftMin[i]<<" ";
        // }
        // cout<<"\n";
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                        rightMax[i]=n-1;
                    }else{
                        rightMax[i]=st.top()-1;
                    }
                    st.push(i);
                
            }
        
        
        // for(int i=0;i<n;i++){
        //     cout<<rightMax[i]<<" ";
        // }
        // cout<<"\n";
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea, (rightMax[i]-leftMin[i]+1)*heights[i]);
        }
        return maxarea;
    }
};