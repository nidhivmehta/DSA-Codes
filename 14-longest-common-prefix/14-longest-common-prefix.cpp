class Solution {
public:
    string solve(string temp, string check) {
        if(temp.size() > check.size())
            swap(temp, check);
        
        string ok="";
        for(int i=0; i<temp.size(); i++) {
            if(temp[i]==check[i])
                ok += temp[i];
            else
                break;
        }
        return ok;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        for(int i=1; i<strs.size(); i++)
        ans = solve(ans, strs[i]);
        
        return ans;
    }
};