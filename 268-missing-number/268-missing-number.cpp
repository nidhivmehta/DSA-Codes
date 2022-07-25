class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        
        int n = nums.size();
        int expectedSum = (n*(n+1))/2;
        
        int requiredSum = expectedSum - sum;
        return requiredSum;
        
    }
};