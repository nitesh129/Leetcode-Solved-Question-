class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k;
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i+=1;
                k++;
            }
        }
        //    for(int m=i+1;m<nums.size();m++){
        //        nums[m]=nums[k];
        //    }
           return i+=1;

        
    }
};