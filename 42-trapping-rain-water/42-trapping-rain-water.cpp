class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
            return 0;
        
        vector<int> maxLeft(n), maxRight(n);
        
        maxLeft[0] = 0;
        int left = height[0];
        for(int i=1; i<n; i++) {
            maxLeft[i] = left;
            left = max(height[i], left);
        }
        
        maxRight[n-1] = 0;
        int right = height[n-1];
        for(int i=n-2; i>=0; i--) {
            maxRight[i] = right;
            right = max(height[i], right);
        }
        
        int trappedWater = 0;
        for(int i=1; i<n-1; i++) {
            if(height[i]<maxLeft[i] && height[i]<maxRight[i])
                trappedWater+= min(maxLeft[i], maxRight[i])-height[i];
        }
        return trappedWater;
    }
};