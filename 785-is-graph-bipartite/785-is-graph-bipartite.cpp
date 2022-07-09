class Solution {
public:
    bool solve(int color[], int node, vector<vector<int>> &graph) {
        color[node] = 1;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto x: graph[node]) {
                if(color[x] == -1) {
                    color[x] = 1-color[node];
                    q.push(x);
                }
                else if(color[x] == color[node])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        int color[n];
        
        memset(color, -1, sizeof color);
        
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(!solve(color, i, graph))
                    return false;
            }
        }
        return true;
    }
};