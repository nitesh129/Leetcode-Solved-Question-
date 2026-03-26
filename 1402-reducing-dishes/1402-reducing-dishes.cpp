class Solution {
public:
    int t[501][501];
    int solve(vector<int>&satisfaction,int indx , int time , int &n){
         if(indx>=n) return 0;
         if(t[indx][time]!=-1) return t[indx][time];
         int take = satisfaction[indx]*time + solve(satisfaction,indx+1,time+1,n);
         int not_take = solve(satisfaction,indx+1,time,n);
         return t[indx][time] =  max(take , not_take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(begin(satisfaction),end(satisfaction));
        memset(t,-1,sizeof(t));
        return solve(satisfaction,0,1,n);
    }
};