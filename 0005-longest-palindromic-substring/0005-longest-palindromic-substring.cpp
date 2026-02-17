class Solution {
public:
    bool solve(string &s , int i , int j, vector<vector<bool>>&t){
        if(i>=j) return true;
        if(t[i][j]!=false) return t[i][j];

        if(s[i]==s[j]){
           return t[i][j] = solve(s,i+1,j-1,t);
        }
        
        return t[i][j] =  false;
    }
    string longestPalindrome(string s) {
      int n = s.length();
      vector<vector<bool>>t(n+1,vector<bool>(n+1,false));
      int maxlen = 1;
      int starting_point = 0;
      for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(solve(s,i,j,t)){
                if(j-i+1 > maxlen){
                    maxlen = j-i+1;
                    starting_point =i;
                }
            }
        }
      }
      return s.substr(starting_point , maxlen);
    }
};