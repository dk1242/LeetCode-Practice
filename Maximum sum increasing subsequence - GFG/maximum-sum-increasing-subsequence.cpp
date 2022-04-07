// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int nums[], int n)  
	{  int ans=0,c=0;
        vector<int>slis(n);
        for(int i=0;i<n;i++)
        slis[i]=nums[i];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && slis[i]<slis[j]+nums[i]){
                    slis[i]=slis[j]+nums[i];
                }
            }
            
        }
        for(int i=0;i<n;i++){
            ans=max(ans, slis[i]);
        }
        return ans;
	    // Your code goes here
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends