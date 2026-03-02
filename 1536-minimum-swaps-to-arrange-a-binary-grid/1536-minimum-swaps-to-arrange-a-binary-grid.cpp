class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>endzeros(n,0);
        for(int i=0;i<n;i++){
            int trail_zero =0;
            for(int j=n-1;j>=0;j--){
                 if(grid[i][j] ==0) trail_zero++;
                 else break;
            }
            endzeros[i] = trail_zero;
        }
        int step = 0;
        for(int i=0;i<endzeros.size();i++){
            int need = n - i - 1;

            int j =i;
            while(j<n && endzeros[j] < need){
                j++;
            }
            if(j==n) return -1;
            step+=j-i;
            while(j>i){
                swap(endzeros[j] , endzeros[j-1]);
                j--;
            }
           
        }
        return step;
    }
};