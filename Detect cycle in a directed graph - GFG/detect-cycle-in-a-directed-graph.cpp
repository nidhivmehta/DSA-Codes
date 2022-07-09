// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkCycle(int vis[], int dfsvis[], int node, vector<int> adj[]) {
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto x: adj[node]) {
            if(!vis[x]) {
                if(checkCycle(vis, dfsvis, x, adj))
                    return true;
            }
            else if(dfsvis[x])
                return true;
        }
        
        dfsvis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V];
        int dfsvis[V];
        
        memset(vis, 0, sizeof vis);
        memset(dfsvis, 0, sizeof dfsvis);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(checkCycle(vis, dfsvis, i, adj))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends