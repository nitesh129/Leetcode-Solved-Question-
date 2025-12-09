class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count_ones =0;
        int max_count = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count_ones++;
            }
            else{
                max_count = max(max_count,count_ones);
                count_ones=0;
            }
        }
        max_count = max(max_count,count_ones);
        return max_count;
    }
};