class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int total_freq = nums.size()/2;
        unordered_map<int ,int>mpp;
        for(int num : nums){
            mpp[num]++;
        }
        int ans =-1;
        for(int num : nums){
            if(mpp[num]==total_freq){
                ans = num;
            }
        }
        return ans;
    }
};