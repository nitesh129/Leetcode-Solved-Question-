class Solution {
public:
    int t[101];
    int solve(vector<int>&nums , int n , int i){
        if(i>=n) return 0;
        if(t[i]!=-1) return t[i];
        return t[i] = max(nums[i] + solve(nums,n,i+2) , solve(nums,n,i+1));
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,n,0);
    }
};