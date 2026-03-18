class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] >k) return 0;
        vector<vector<long long >>presum(m,vector<long long >(n,0));
        int row =0;
        presum[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            presum[row][i] = presum[row][i-1] + grid[row][i];
        }
        int col=0;
        for(int i=1;i<m;i++){
            presum[i][col] = presum[i-1][col] + grid[i][col];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                presum[i][j] =  (grid[i][j] + presum[i-1][j] + presum[i][j-1]) - presum[i-1][j-1];
            }
        }
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(presum[i][j] <=k){
                    ans++;
                }
            }
        }
        return ans;

    }
};