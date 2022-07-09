class Solution {
public:
    void solve(int x, int y, int r, int c, vector<vector<char>>& matrix) {
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')
            return;
        
        matrix[x][y] = '2';
        
        solve(x-1, y, r, c, matrix);
        solve(x, y+1, r, c, matrix);
        solve(x+1, y, r, c, matrix);
        solve(x, y-1, r, c, matrix);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int totalIslands = 0;
        int rows = grid.size();
        
        if(rows == 0)
            return 0;
        
        int cols = grid[0].size();
        
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
                if(grid[i][j] == '1') {
                    solve(i, j, rows, cols, grid);
                    totalIslands++;
                }
        return totalIslands;
                    
        
    }
};