class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> candidates, int target, int index, int curSum, vector<int> &temp) {
        if(curSum > target)
            return;
        if(curSum == target) {
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size()) {
            if(curSum == target)
                ans.push_back(temp);
            return;
        }
        curSum+=candidates[index];
        temp.push_back(candidates[index]);
        helper(candidates, target, index, curSum, temp);
        
        curSum-=candidates[index];
        temp.pop_back();
        helper(candidates, target, index+1, curSum, temp);

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target, 0, 0, temp);
        return ans;
    }
};