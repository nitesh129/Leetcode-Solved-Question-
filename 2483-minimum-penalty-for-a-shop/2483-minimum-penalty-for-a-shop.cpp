class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
       vector<int>suffix(n+1,0);
       suffix[n] =0;
       for(int i=n-1;i>=0;i--){
          suffix[i] = suffix[i+1] + (customers[i] == 'Y' ? 1 : 0);
       }
       int N_count =0;
       int min_ans = INT_MAX;
       int min_penalty = INT_MAX;
       int ans =0;
       for(int i=0;i<=n;i++){
         int penalty = suffix[i] + N_count;
         if(penalty < min_penalty){
            min_penalty = penalty;
            ans =i;
         }
           
          if(customers[i]=='N') N_count++;
       }
        return ans;
    }
};