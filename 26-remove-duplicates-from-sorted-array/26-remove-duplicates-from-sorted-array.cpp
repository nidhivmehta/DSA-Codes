class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int i = 0;
        int j=1;
        while(j<nums.size()) {
            if(nums[i] == nums[j])
                j++;
            else {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};