class Solution {
public:
    int t[201][201];
    int solve(int m,int n,vector<vector<int>>& grid,int i,int j){
       if(i==m-1 && j==n-1) return grid[i][j];
       if(t[i][j]!=-1) return t[i][j];
       if(i==m-1) return t[i][j] =  grid[i][j] + solve(m,n,grid,i,j+1);
       else if(j==n-1) return t[i][j] =  grid[i][j] + solve(m,n,grid,i+1,j);
       else return  t[i][j] = grid[i][j] +  min(solve(m,n,grid,i,j+1) , solve(m,n,grid,i+1,j));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(m,n,grid,0,0);
    }
};