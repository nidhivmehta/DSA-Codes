class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = 0;
        int n = s.size();
        int j;
        
        while(i<n) {
            while(i<n && s[i]== ' ')
                i++;
            
            if(i>=n)
                break;
            
            j=i+1;
            
            while(j<n && s[j]!=' ')
                j++;
            
            string help = s.substr(i, j-i);
            
            if(ans.size() == 0)
                ans = help;
            else
                ans = help + " " + ans;
            
            i=j+1;
        }
        return ans;
    }
};