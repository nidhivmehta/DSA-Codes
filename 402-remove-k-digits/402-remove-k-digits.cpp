class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> myStack;
        
        for(auto c: num) {
            while(!myStack.empty() && k>0 && c<myStack.top()) {
                myStack.pop();
                k--;
            }
                
            if(!myStack.empty() || c!='0')
                myStack.push(c);
        }
        
        while(!myStack.empty() && k--)
            myStack.pop();
        if(myStack.empty())
            return "0";
        
        while(!myStack.empty()) {
            num[n-1] = myStack.top();
            myStack.pop();
            n--;
        }
        
        return num.substr(n);
        
    }
};