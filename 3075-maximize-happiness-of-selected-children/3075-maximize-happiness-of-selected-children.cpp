class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long result =0 ;
        sort(begin(happiness),end(happiness),greater<int>());
        int count =0;
        for(int i=0;i<k;i++){
            result+=max(happiness[i]-count,0);
            count+=1;
        }

       return result;
    }
};