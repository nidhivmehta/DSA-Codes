//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        set<char> distinctChar;
        for(char s: str)
            distinctChar.insert(s);
            
        int n = distinctChar.size();
        int i = 0;
        int j = 0;
        int ans = str.size();
        unordered_map<char, int> mpp;
        while(i<str.size()) {
            mpp[str[i]]++;
            if(mpp.size()==n) {
                while(mpp[str[j]]>1) {
                    mpp[str[j]]--;
                    j++;
                }
                ans = min(ans, i-j+1);
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends