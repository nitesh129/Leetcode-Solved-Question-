class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>count;
        for(int x : nums){
            count[x]++;
        }
        int duplicate =-1 , missing =-1;
         for(int i=1;i<=nums.size();i++){
            if(count[i]>=2) duplicate =i; 
            if(i!=0 && count[i] ==0) missing = i;
       }
       return {duplicate , missing};
    }
};