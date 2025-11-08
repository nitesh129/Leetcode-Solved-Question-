class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(begin(nums),end(nums));
        int ans =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max) continue;
            ans+=max-nums[i];
        }
        return ans;
    }
};