class NumArray {
public:
    int n, sum=0;
    vector<int>seg, num;
//     void build(vector<int>&nums, int ind, int l, int r){
//         if(l==r){
//             seg[ind]=nums[l];
//             return;
//         }
//         int mid=(l+r)/2;
//         build(nums, 2*ind+1, l, mid);
//         build(nums, 2*ind+2, mid+1, r);
//         seg[ind]=seg[ind*2+1]+seg[ind*2+2];
//     }
//     void updateSeg(int ind, int l, int r, int pos, int val){
//         if(pos<l || pos>r) return;
        
//         if(l==r && l==pos){
//             seg[ind]=val;
//             return;
//         }

//         int mid=(l+r)/2;
//         updateSeg(2*ind+1,l,mid,pos,val); // left child
//         updateSeg(2*ind+2,mid+1,r,pos,val); // right child
//         seg[ind]=seg[2*ind+1]+seg[2*ind+2];
//     }
//     int getSum(int ind, int sl, int sr, int l, int r){
//         if(l<=sl && r>=sr){
//             return seg[ind];
//         }
//         if(l>sl || r<sr)
//             return 0;
//         int mid=sl+(sr-sl)/2;
//         return getSum(2*ind+1, sl, mid, l, r)+getSum(2*ind+2, mid+1, sr, l, r);
//     }
    NumArray(vector<int>& nums) {
        int n=nums.size();
        // seg.resize(4*n, 0);
        num=nums;
        // build(nums, 0, 0, n-1);
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        // cout<<val-num[index];
        // for(int i=0;i<seg.size();i++){
        //     cout<<seg[i];
        // }
        // cout<<"\n";
        // updateSeg(0, 0, n-1, index, val);
        // // num[index]=val;
        // for(int i=0;i<seg.size();i++){
        //     cout<<seg[i];
        // }
        sum-=num[index];
        num[index]=val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        // return getSum(0, 0, n-1, left, right);
        int res=sum; 
        for(int i=0;i<left;i++){    //subtract all element before left and after right
            res-=num[i];
        }
        for(int i=right+1;i<num.size();i++){
            res-=num[i];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */