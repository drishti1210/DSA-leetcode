class Solution {
public:
    int longestValidParentheses(string s) {
        int cntl=0,cntr=0,ansl=0,ansr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                cntl++;
            if(s[i]==')')
                cntr++;
            if(cntr>cntl)
            {
                cntr=0;
                cntl=0;
            }
            else if(cntr==cntl)
              ansl=max(ansl,cntl+cntr);
        }
        cntl=0;
        cntr=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')
                cntl++;
            if(s[i]==')')
                cntr++;
            if(cntl>cntr){
                cntl=0;
                cntr=0;
                }
            else if(cntl==cntr)
              ansr=max(ansr,cntl+cntr);
        }
        return max(ansl,ansr);
    }
};