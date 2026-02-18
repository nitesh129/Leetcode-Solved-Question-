class Solution {
public:
    int t[2501][2501];
    int solve(int indx , int prev , vector<int>&nums , int n){
        if(indx>=n) return 0;
        if(prev!=-1 && t[indx][prev]!=-1) return t[indx][prev];
        int take =0;
        int not_take =0;
        if(prev==-1 || nums[prev] < nums[indx]){
            take =  1 + solve(indx+1,indx,nums,n);
        }
       not_take = solve(indx+1,prev,nums,n);
       if(prev!=-1){
          return t[indx][prev] = max(take,not_take);
       }
       return max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums,n);
    }
};