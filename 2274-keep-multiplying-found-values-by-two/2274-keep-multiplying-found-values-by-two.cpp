class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int temp = original ;
        sort(begin(nums),end(nums));
        for(int i=0;i<nums.size();i++){
            if(nums[i]==temp){
                temp = temp*2;
            }
        }
        return temp;
    }
};