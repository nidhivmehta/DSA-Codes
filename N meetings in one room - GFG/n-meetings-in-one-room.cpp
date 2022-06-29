// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    bool static comparator(pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) 
            return a.first < b.first;
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> V(n);
        for(int i=0; i<n; i++)
            V[i] = {start[i], end[i]};
            
        sort(V.begin(), V.end(), comparator);
        
        int i = 0;
        int j = 1;
        int count = 1;
        
        while(j < n) {
            if(V[i].second < V[j].first) {
                count++;
                i = j;
                j++;
            }
            else
                j++;
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends