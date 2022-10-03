class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        vector<int> index;
        
        for(int i=0; i<nums.size(); i++) {
            if(mpp.find(target-nums[i]) == mpp.end())
                mpp[nums[i]] = i;
            else if(mpp.find(target-nums[i]) != mpp.end()) {
                index.push_back(mpp[target-nums[i]]);
                index.push_back(i);
            }  
        }
        return index;
    }
};