class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0)
            return 0;
        
        int i=0;
        while(i<s.length() && s[i]==' ')
            i++;
        
        s = s.substr(i);
        
        int sign = +1;
        long ans = 0;
        
        if(s[0]=='-')
            sign = -1;
        
        i = (s[0]=='+' || s[0]=='-')? 1:0;
        
        int maxi = INT_MAX;
        int mini = INT_MIN;
        
        while(i<s.length()) {
            if(s[0]==' ' || !isdigit(s[i]))
                break;
            
            ans = ans*10 + s[i]-'0';
            
            if(sign==1 && ans*sign>maxi)
                return maxi;
            if(sign==-1 && ans*sign<mini)
                return mini;
            
            i++;
        }
        
        return ans*sign;
    }
};