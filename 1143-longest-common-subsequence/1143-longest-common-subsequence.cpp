class Solution {
public:
    int t[1001][1001];
    int solve(string &s , string &l , int n , int m){
        if(n==0 || m==0) return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(s[n-1] == l[m-1]){
            return t[n][m] =  1 + solve(s,l,n-1,m-1);
        }
        else return t[n][m] =  max(solve(s,l,n-1,m),solve(s,l,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        memset(t,-1,sizeof(t));
        return solve(text1,text2,n,m);
    }
};