class Solution {
public:
    int find(int curr_element){
        int sum =0;
        int total_fac_count =0;
        for(int fact=1;fact<=sqrt(curr_element);fact++){
              if((curr_element % fact) == 0){
                   int other = curr_element/fact;
                   if(other == fact){
                       total_fac_count+=1;
                       sum+=fact;
                   }
                   else{
                      total_fac_count+=2;
                      sum+=fact+other;
                   }
              }
              if(total_fac_count>4) return 0;
        }
         return total_fac_count == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int result =0;
        for(int i=0;i<n;i++){
            result+=find(nums[i]);
        }
        
        return result;
    }
};