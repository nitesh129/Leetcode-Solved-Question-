class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jobDifficulty ,int n,int indx,int d){
         if(d==1){
            int maxd = jobDifficulty[indx];
            for(int i=indx;i<n;i++){
                maxd = max(maxd,jobDifficulty[i]);
            }
            return maxd;
         }
         if(t[indx][d]!=-1) return t[indx][d];
         int maxval = INT_MIN;
         int final_result = INT_MAX;
         for(int i=indx;i<=n-d;i++){
             maxval = max(maxval , jobDifficulty[i]);
             int result = maxval + solve(jobDifficulty,n,i+1,d-1);
             final_result = min(final_result , result);
         }
         return t[indx][d] = final_result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d)return -1;
        memset(t,-1,sizeof(t));
        return solve(jobDifficulty,n,0,d);
    }
};