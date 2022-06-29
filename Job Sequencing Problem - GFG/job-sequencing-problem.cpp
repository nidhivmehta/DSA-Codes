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
    bool static comparator(Job a, Job b) {
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comparator);
        
        int maxi = arr[0].dead;
        
        int i, j;
        for(i=1; i<n; i++) {
            maxi = max(maxi, arr[i].dead);
        }
        
        int slot[maxi+1];
        for(i=1; i<=maxi; i++)
            slot[i] = -1;
            
        int jobCount = 0;
        int profit = 0;
        
        for(i=0; i<n; i++) {
            for(j=arr[i].dead; j>0; j--) {
                if(slot[j] == -1) {
                    slot[j] = arr[i].id;
                    jobCount++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobCount, profit};
        
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