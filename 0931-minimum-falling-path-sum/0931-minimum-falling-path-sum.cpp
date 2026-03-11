class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
       vector<vector<int>>t(n,vector<int>(n));
       int row =0;
       for(int col =0;col<n;col++){
          t[row][col] = matrix[row][col];
       }

       for(int row=1;row<n;row++){
          for(int col=0;col<n;col++){
             t[row][col] = matrix[row][col] + min({t[row-1][col] , (col-1>=0) ? t[row-1][col-1] : INT_MAX , (col+1<n) ? t[row-1][col+1] : INT_MAX});
          }
       }
       int result = INT_MAX;
       int r = n-1;
       for(int col=0;col<n;col++){
          result = min(result , t[r][col]);
       }
       return result;
    }
};