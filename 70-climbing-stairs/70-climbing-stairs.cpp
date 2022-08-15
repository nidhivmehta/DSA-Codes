class Solution {
public:
    int solve(int i, vector<int>& dp) {
        if(i==0)
            return 1;
        
        if(i==1)
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int one = solve(i-1, dp);
        int two = solve(i-2, dp);
        
        return dp[i] = one + two;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};