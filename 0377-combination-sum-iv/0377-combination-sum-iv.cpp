class Solution {
public:
    int n;
    int t[201][1001];
    int solve(vector<int>&nums , int indx , int target){
        if(target ==0) return 1;
        if(indx>=n || target < 0) return 0;
        if(t[indx][target] !=-1) return t[indx][target];
        int take_indx = solve(nums,0,target-nums[indx]); // agar take kar liya to vaps se 0 se check kaar [2,1,1];
        int not_take_indx = solve(nums,indx+1,target);
        return t[indx][target] =  take_indx + not_take_indx;
    }
   
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,target);
        
    }
};