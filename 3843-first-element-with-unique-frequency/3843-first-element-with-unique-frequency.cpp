class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int num : nums){
            mpp[num]++;
        }
        unordered_map<int,int>freqmap;
        for(auto &it : mpp){
            freqmap[it.second]++;
        }
        for(int i=0;i<nums.size();i++){
            int freq = mpp[nums[i]];
            if(freqmap[freq]==1){
                return nums[i];
            }
        }
        return -1;
    }
};