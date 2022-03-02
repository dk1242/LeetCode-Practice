// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        vector<int>res;
        // for(int i=0;i<n;i++){
        //     cout<<arr[i].profit<<" ";
        // }
        int result[n];
        bool slot[n]={false};
        int profit=0,c=0;
        for(int i=0;i<n;i++){
            for(int j=min(arr[i].dead, n)-1; j>=0; j--){
                if(slot[j]==false){
                    c++;
                    profit+=arr[i].profit;
                    slot[j]=true;
                    break;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<slot[i];
        // }
        // int c=0, ress=0;
        // for(int i=0;i<n;i++){
        //     if(slot[i]){
        //         c++;
        //         ress+=arr[result[i]].profit;
        //     }
        // }
        res.push_back(c);
        res.push_back(profit);
        return res;
        // your code here
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends