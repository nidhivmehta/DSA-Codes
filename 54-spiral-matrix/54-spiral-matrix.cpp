class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        int dir = 0;
        int i;
        
        vector<int> ans;
        
        while(top<=bottom && left<=right) {
            if(dir==0) {
                for(i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                    top++;
                }
            
            if(dir==1) {
                for(i=top; i<=bottom; i++)
                    ans.push_back(matrix[i][right]);
                    right--;
                }
            
            if(dir==2) {
                for(i=right; i>=left; i--)
                    ans.push_back(matrix[bottom][i]);
                    bottom--;
                }
            
            if(dir==3) {
                for(i=bottom; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                    left++;
                }
            dir = (dir+1)%4;
        }
        return ans;
    }
};