class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int k = 0;
        int n = chars.size();
        
        while(i<n) {
            while(j<n && chars[j] == chars[i])
                j++;
            
            chars[k] = chars[i];
            k++;
            
            if(j-i>1) 
                for(char s: to_string(j-i)) {
                    chars[k] = s;
                    k++;
                }
                i = j;
            }
        return k;
    }
};