//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    
	    int maxi=0;
	    int ans=0;
	    int total = m*n;
	    int count_zero=0;
	    
	    for(int i=0;i<n;i++){
	        int count=0;
	        for(int j=0;j<m;j++){
	            if(arr[i][j]==1)
	            count++;
	            else{
	                count_zero++;
	            }
	        }
	        if(maxi<count){
	            maxi=count;
	            ans=i;
	        }
	    }
	    if(count_zero==total)
	      return -1;
	      
	    return ans;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends