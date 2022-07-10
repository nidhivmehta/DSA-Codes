// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
	    vis[node] = 1;
	    
	    for(auto x: transpose[node]) {
	        if(!vis[x]) {
	            revDfs(x, vis, transpose);
	        }
	    }
	}
	
	void dfsTopo(vector<int> &vis, stack<int> &st, int node, vector<int> adj[]) {
	    vis[node] = 1;
	    
	    for(auto x: adj[node]) {
	        if(!vis[x])
	            dfsTopo(vis, st, x, adj);
	    }
	    st.push(node);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V, 0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i])
                dfsTopo(vis, st, i, adj);
        }
        
        vector<int> transpose[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto x: adj[i])
                transpose[x].push_back(i);
        }
        
        int count = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(!vis[node]) {
                count = count + 1;
                revDfs(node, vis, transpose);
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends