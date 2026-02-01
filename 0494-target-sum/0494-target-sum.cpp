class Solution {
public:
    int t[21][1000001];
    int solve(vector<int>&nums , int target , int indx){
        if(target < 0) return 0;
        if(indx ==0){
            if(target ==0 && nums[indx] ==0) return 2;
            if(target ==0 || nums[indx] ==target) return 1;
            return 0;
        }
        if(t[indx][target]!=-1) return t[indx][target];
        int not_take = solve(nums,target,indx-1);
        int take = solve(nums,target-nums[indx],indx-1);
        return t[indx][target] =  take + not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int total_sum = accumulate(begin(nums),end(nums),0);
        if(target > total_sum) return 0;
        if((target+ total_sum) %2 !=0) return 0;
        int new_sum = (target + total_sum)/2;
        memset(t,-1,sizeof(t));
        return solve(nums,new_sum, n-1);

    }
};