class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi_ans = 0;
        int n = nums.size();
        sort(begin(nums),end(nums));
        int i=0 , j=n-1;
        while(i<j){
            maxi_ans = max(maxi_ans , (nums[i] + nums[j]));
            i++;
            j--;
        }
        return maxi_ans;
    }
};