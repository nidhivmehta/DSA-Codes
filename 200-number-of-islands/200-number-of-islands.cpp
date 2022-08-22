class Solution {
public:
    void solve(int x, int y, int r, int c, vector<vector<char>>& grid) {
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y] != '1')
            return;
        
        grid[x][y] = '2';
        
        solve(x-1, y, r, c, grid);
        solve(x+1, y, r, c, grid);
        solve(x, y-1, r, c, grid);
        solve(x, y+1, r, c, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int totalIsland = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(rows == 0)
            return 0;
        
        for(int i=0; i<rows; i++) 
            for(int j=0; j<cols; j++)
                if(grid[i][j] == '1') {
                    solve(i, j, rows, cols, grid);
                    totalIsland++;
                    }
        return totalIsland;     
    }
};