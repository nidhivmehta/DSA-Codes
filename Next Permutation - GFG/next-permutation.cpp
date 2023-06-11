//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> nums){
        int ind = -1;
        int i;

        for(i=N-2; i>=0; i--)
            if(nums[i]<nums[i+1])
                break;

        ind = i;

        if(ind==-1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        for(i=N-1; i>=ind; i--)
            if(nums[i]>nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }

        reverse(nums.begin()+ind+1, nums.end());

        return nums;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends