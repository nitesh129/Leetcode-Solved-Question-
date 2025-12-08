class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int count =0;
        int maxi=INT_MIN;
        for(auto &num:nums){
            mpp[num]++;
            maxi = max(maxi,mpp[num]);
        }
        for(auto &num : nums){
            if(mpp[num]==maxi){
                count+=1;
            }
        }
        
        return count;
    }
};