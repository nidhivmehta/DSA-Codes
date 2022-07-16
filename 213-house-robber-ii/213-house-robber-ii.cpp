class Solution {
public:
    int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector dp(n, -1);
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1; i<n; i++) {
        int take = nums[i];
            if(i>1)
                take += prev2;

        int notTake = 0 + prev;

        int cur = max(take, notTake);

        prev2 = prev;
        prev = cur;
    }
    return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        
        if(n == 1)
            return nums[0];
        
        for(int i=0; i<n; i++) {
            if(i != 0)
                temp1.push_back(nums[i]);
            if(i != n-1)
                temp2.push_back(nums[i]);
        }
        
        return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
};