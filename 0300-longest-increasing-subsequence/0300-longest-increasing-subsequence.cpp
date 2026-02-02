class Solution {
public:
    int t[2501][2501];
    int solve(vector<int>&nums , int n , int indx , int prev){
        if(indx >= n){
           return 0;
        }
        if(t[indx][prev+1]!=-1) return t[indx][prev+1];
        int take =0;
        if(prev==-1 || nums[prev] < nums[indx]){
             take = 1+solve(nums,n,indx+1,indx);
        }
        int not_take = solve(nums,n,indx+1,prev);
        return t[indx][prev+1] = max(take,not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
      return solve(nums,n,0,-1);
    
    }
};