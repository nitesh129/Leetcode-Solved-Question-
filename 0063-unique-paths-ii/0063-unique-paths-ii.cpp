class Solution {
public:
    int t[101][101];
    int solve(int m , int n ,vector<vector<int>>& obstacleGrid,int i,int j){
        if(i>=m || j>=n || obstacleGrid[i][j] == 1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(t[i][j]!=-1) return t[i][j];
        int right = solve(m,n,obstacleGrid,i,j+1);
        int down = solve(m,n,obstacleGrid,i+1,j);
        return t[i][j] =  right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =  obstacleGrid.size();
        int n =  obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return solve(m,n,obstacleGrid,0,0);
    }
};