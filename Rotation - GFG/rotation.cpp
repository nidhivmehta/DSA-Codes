//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int low = 0;
        int high = n-1;
        int ans = INT_MAX;
        int index = -1;

        while(low<=high) {
            int mid = (low+high)/2;

            if(nums[low]<=nums[mid]) {
                if(nums[low]<ans) {
                    index = low;
                    ans = nums[low];
                }
                low = mid+1;
            }
            else{
                high = mid-1;
                if(nums[mid]<ans) {
                    index = mid;
                    ans = nums[mid];
                }
            }
        }
        return index;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends