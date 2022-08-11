class Solution {
public:
    vector<vector<int>> loc{{-2,-1},{-2,1},{-1,-2},{1,-2},{-1,2},{1,2},{2,-1},{2,1}};
    double f(int i,int j,int k,int n,vector<vector<vector<double>>> &dp){
        if(i < 0 || i >= n || j < 0 || j >= n){
            return 0.0;
        }
        
        if(k == 0){
            return 1.0;
        }
        
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        double pick = 0.0;
        for(auto x : loc){
            pick += f(i + x[0],j + x[1],k-1,n,dp)/8.0;
        }
        return dp[i][j][k] = pick;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return f(row,column,k,n,dp);
    }
};