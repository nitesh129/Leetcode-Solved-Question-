class Solution {
public:
    int t[101][101];
    int solve(int m ,int n, int i,int j){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(t[i][j]!=-1) return t[i][j];
        int right = solve(m,n,i,j+1);
        int down = solve(m,n,i+1,j);
        return t[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<bool>>visited(m,vector<bool>(n,false));
        memset(t,-1,sizeof(t));
       return solve(m,n,0,0);
        
    }
};