class Solution {
public:
   int t[101][101];
    bool solve(int i,int open , string &s){
         if(i==s.length()) return open==0;
         if(t[i][open]!=-1) return t[i][open];
         bool isvalid = false;
         if(s[i]=='*'){
            isvalid|=solve(i+1,open+1,s);
            isvalid|=solve(i+1,open,s);
            if(open >0){
                isvalid|=solve(i+1,open-1,s);
            }
         }
         else if(s[i]=='(') isvalid|=solve(i+1,open+1,s);
         else if(open > 0) isvalid|=solve(i+1,open-1,s);
         return t[i][open] =  isvalid;
    }
    bool checkValidString(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,s);
    }
};