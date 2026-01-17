class Solution {
public:
    long long  t[1000001][2];
    long long solve(int i , vector<int>&nums,int &n , bool flag){
        if(i>n-1) return 0;
        if(t[i][flag]!=-1) return t[i][flag];
        long long skip = solve(i+1,nums,n,flag);
        long long  val = nums[i];
        if(flag == false){
            val = -val;
        } 
        long long  take = solve(i+1,nums,n,!flag) + val;
        return t[i][flag]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,n,true);
    }
};