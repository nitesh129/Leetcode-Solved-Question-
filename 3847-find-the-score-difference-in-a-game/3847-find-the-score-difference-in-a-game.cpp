class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        bool active_one = true;
        bool active_two = false;
        int count_one =0;
        int count_two =0;
        for(int i=0;i<n;i++){
           if(nums[i] %2 !=0){
               active_one = !active_one;
           }
           if((i%6)==5){
             active_one = !active_one;
           }

           if(active_one){
              count_one+=nums[i];
           }
           else{
              count_two+=nums[i];
           }

       }
       return count_one - count_two;
}
};