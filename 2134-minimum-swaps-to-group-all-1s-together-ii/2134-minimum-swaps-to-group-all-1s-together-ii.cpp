class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(2*n,0);
        for(int i=0;i<n;i++){
            arr[i] =  nums[i];
            arr[i+n] = nums[i];
        }
        int total_one = count(nums.begin(),nums.end(),1);
         if(total_one ==0) return 0;
        int i=0,j=0;
        int maxcount =0;
        int count_one =0;
        while(j<2*n){
            if(arr[j]==1) count_one++;
            while(j-i+1 > total_one){
                if(arr[i]==1)count_one--;
                i++;
            }
            if(j-i+1 == total_one){
                maxcount = max(maxcount , count_one);
            }
            j++;
        }
        return total_one - maxcount;

    }
};