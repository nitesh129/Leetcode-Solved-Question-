class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = 3;
        vector<bool>isflipped(n,false);
        int flip =0;
        int prevflip =0;
        for(int i=0;i<n;i++){
            if(i>=k && isflipped[i-k]){
                prevflip--;
            }
            if(prevflip % 2 == nums[i]){
                if(i+k > n) return -1;
                flip++;
                prevflip++;
                isflipped[i] = true;
            } 
        }
        return flip;
    }
};