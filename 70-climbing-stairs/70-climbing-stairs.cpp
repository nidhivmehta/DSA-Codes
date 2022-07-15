class Solution {
public:
    int solve(int n, vector<int> &dp, int index) {
        if(index == 0)
            return 1;
        if(index == 1)
            return 1;
        if(dp[index] != -1)
            return dp[index];
        
        return dp[index] = solve(n, dp, index-1) + solve(n, dp, index-2);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp, n);
    }
};