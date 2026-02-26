class Solution {
public:
    int t[501][501];
    int solve(int i,int j,int m,int n,string &s1 , string &s2){
        if(i==m){
            return n-j;
        }
        else if(j==n){
            return m-i;
        }
        if(t[i][j]!=-1) return t[i][j];
        if(s1[i] == s2[j]){
            return t[i][j] =  solve(i+1,j+1,m,n,s1,s2);
        }
        int insert = 1 + solve(i,j+1,m,n,s1,s2);
        int del = 1 + solve(i+1,j,m,n,s1,s2);
        int replace = 1+solve(i+1,j+1,m,n,s1,s2);
        return t[i][j] = min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n,word1,word2);
    }
};