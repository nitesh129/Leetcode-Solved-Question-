class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                for(int k=0;k<nums.size();k++){
                    if(i!=j && j!=k && i!=k){
                        maxi = max(maxi , (nums[i] + nums[j] - nums[k]));
                    }
                }
            }
        }
        return maxi;
    }
};