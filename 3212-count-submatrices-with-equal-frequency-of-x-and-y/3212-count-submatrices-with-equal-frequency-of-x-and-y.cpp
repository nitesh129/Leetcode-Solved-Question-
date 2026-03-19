class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>>currsumx(m,vector<long long>(n,0));
        vector<vector<long long>>currsumy(m,vector<long long>(n,0));
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                currsumx[i][j] = (grid[i][j]=='X');
                currsumy[i][j] = (grid[i][j]=='Y');

                if(i-1>=0){
                    currsumx[i][j]+= currsumx[i-1][j];
                    currsumy[i][j]+= currsumy[i-1][j];
                }
                if(j-1>=0){
                    currsumx[i][j]+= currsumx[i][j-1];
                    currsumy[i][j]+= currsumy[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    currsumx[i][j]-= currsumx[i-1][j-1];
                    currsumy[i][j]-= currsumy[i-1][j-1];
                }

                if(currsumx[i][j] == currsumy[i][j] && currsumx[i][j] >0){
                    count++;
                }
            }
        }
        return count;
    }
};