//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int lower_bound(int nums[], int target, int n) {
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high) {
            int mid = (low+high)/2;

            if(nums[mid]>=target) {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }

    int upper_bound(int nums[], int target, int n) {
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high) {
            int mid = (low+high)/2;

            if(nums[mid]>target) {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    
	int count(int nums[], int n, int target) {

        int lb = lower_bound(nums, target, n);
        if(lb==n || nums[lb]!=target)
            return 0;
        int ub = upper_bound(nums, target, n)-1;
        return ub-lb+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends