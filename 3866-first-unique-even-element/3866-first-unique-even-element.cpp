class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int num : nums){
            mpp[num]++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]%2==0 && mpp[nums[i]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};