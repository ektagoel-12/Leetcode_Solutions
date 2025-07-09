class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        if(s.length()==0)return true;
        if(s.length()==1)return false;
        stk.push(s[0]);
        int i=1;
        while(i<s.length())
        {
            if(!stk.empty() && ((stk.top()=='(' &&s[i]==')') ||
                (stk.top()=='{' &&s[i]=='}') ||
                (stk.top()=='[' &&s[i]==']')  ))
            {
                stk.pop();
            }
            else
            {stk.push(s[i]);}
            i++;
        }
        if(stk.empty())return true;
        return false;
    
    }
};