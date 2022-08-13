class Solution {
public:
    void solve(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums) {
        if(index == nums.size())
            ans.push_back(temp);
        
        else {
            temp.push_back(nums[index]);
            solve(index+1, temp, ans, nums);

            temp.pop_back();
            solve(index+1, temp, ans, nums);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0, temp, ans, nums);
        
        return ans;
        
    }
};