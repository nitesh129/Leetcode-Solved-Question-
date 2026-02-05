class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            int shift = nums[i]%n;
           int new_indx = (i+shift)%n;
           if(new_indx<0){
              new_indx+=n;
           }
           result[i] = nums[new_indx];
        }
        return result;
    }
};