class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string &s1,string&s2,int n,int m){
         if(i==n || j==m) return 0;
         if(t[i][j]!=-1) return t[i][j];
         if(s1[i]==s2[j]){
            return t[i][j] =  1+solve(i+1,j+1,s1,s2,n,m);
         }
         else{
            return t[i][j] = max((solve(i+1,j,s1,s2,n,m)),(solve(i,j+1,s1,s2,n,m)));
         }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        memset(t,-1,sizeof(t));
         return solve(0,0,text1,text2,n,m);
    }
};