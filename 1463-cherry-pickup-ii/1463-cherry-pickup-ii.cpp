class Solution {
public:
    int solve(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if(j1<0 || j1>=c || j2<0 || j2>=c)
            return -1e9; 
        
        if(i == r-1) {
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        int maxi = INT_MIN;
        for(int di=-1; di<=1; di++) {
            for(int dj=-1; dj<=1; dj++) {
                int value;
                
                if(j1 == j2)
                    value = grid[i][j1] + solve(i+1, j1+di, j2+dj, r, c, grid, dp);
                else 
                    value = grid[i][j1] + grid[i][j2] + solve(i+1, j1+di, j2+dj, r, c, grid, dp);
                
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
}
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (c, -1)));
        
        return solve(0, 0, c-1, r, c, grid, dp);
        
    }
};