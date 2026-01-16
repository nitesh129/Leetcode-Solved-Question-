class Solution {
public:
   int t[101];
   int solve(vector<int>&nums , int i){
      if(i>=nums.size()) return 0;
      if(t[i]!=-1) return t[i];
      return t[i] = max((nums[i] + solve(nums,i+2)) , (solve(nums,i+1)));
   }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};