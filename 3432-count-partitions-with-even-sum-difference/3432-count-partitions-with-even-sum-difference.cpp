class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sumdiff =0;
        int count =0;
        int leftsum =0;
        int rightsum=0;
        for(int i=0;i<nums.size();i++){
            leftsum+=nums[i];
            rightsum=0;
            for(int j=i+1;j<nums.size();j++){
                 rightsum+=nums[j];
            }
            sumdiff = leftsum - rightsum;
            if(sumdiff%2==0) count++;
        }
        return count==0 ? 0 : count -1;
    }
};