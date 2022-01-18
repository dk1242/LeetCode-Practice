class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int num) {
        int zero=0, count=0;
        int n=flowerbed.size();
        if(n==1)
            return flowerbed[0]==0 || num==0;
        for(int i=0;i<n;i++){
            if(flowerbed[i]==0){
                if(i==0){
                    if(flowerbed[i+1]==0){
                    count++;
                    flowerbed[i]=1;}
                    else continue;
                }else if(i==n-1 && i>0){
                    if(flowerbed[i-1]==0){
                    count++;
                    flowerbed[i]=1;}
                    else continue;
                }else if(n>=3 && flowerbed[i+1]==0 && flowerbed[i-1]==0){
                    count++;
                    flowerbed[i]=1;
                }
            }
        }
        if(count>=num){
            return true;
        }else return false;
    }
};