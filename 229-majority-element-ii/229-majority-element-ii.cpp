class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size();
        int num1=-1, num2=-1, c1=0, c2=0;
        
        for(int el: nums) {
            if(el == num1)
                c1++;
            else if(el == num2)
                c2++;
            else if(c1==0) {
                num1 = el;
                c1++;
            }
            else if(c2==0) {
                num2 = el;
                c2++;
            }
            else {
                c1--;
                c2--;
            }
            
        }
        
        vector<int> ans;
        
        c1 = c2 = 0;
        
        for(int el: nums) {
            if(el == num1)
                c1++;
            else if(el == num2)
                c2++;
        }
        
        if(c1 > N/3)
            ans.push_back(num1);
        if(c2 > N/3)
            ans.push_back(num2);
        
    return ans;
    }
};
    
    