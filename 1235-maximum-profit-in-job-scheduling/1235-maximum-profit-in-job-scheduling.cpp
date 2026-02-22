class Solution {
public:
    int n;
    int getnext(vector<vector<int>>&job , int start , int curr_job_end){
        int end = n-1;
        int result = n+1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(job[mid][0] >= curr_job_end){
                result = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return result;

    }
    int solve(vector<vector<int>>&job,int i,vector<int>&t){
        if(i>=n){
            return 0;
        }
        if(t[i]!=-1) return t[i];
        int next = getnext(job,i+1,job[i][1]);
        int take = job[i][2] + solve(job,next,t);
        int  not_take = solve(job,i+1,t);
        return  t[i] = max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>&profit) {
         n =  startTime.size();
         vector<int>t(n+1,-1);
         vector<vector<int>>job(n,vector<int>(3,0));
         for(int i=0;i<n;i++){
            job[i][0] =  startTime[i];
            job[i][1] =  endTime[i];
            job[i][2] = profit[i];
         }

         sort(begin(job),end(job));
         return solve(job,0,t);

    }
};