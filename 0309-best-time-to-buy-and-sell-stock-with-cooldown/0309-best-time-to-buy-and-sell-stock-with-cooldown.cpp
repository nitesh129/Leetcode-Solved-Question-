class Solution {
public:
   int t[5001][2];
   int solve(vector<int>&prices , int day , bool buy,int n){
      if(day>=n) return 0;
      int profit =0;
      if(t[day][buy]!=-1) return t[day][buy];
      if(buy){
         int take = solve(prices,day+1,false,n) - prices[day];
         int not_take = solve(prices , day+1,true,n);
         profit = max({ profit,take , not_take});
      }
      else { // go for sell
          int take = prices[day] + solve(prices,day+2,true,n);
          int not_take = solve(prices,day+1,false,n);
          profit = max({profit , take , not_take});
      }
      return t[day][buy] =  profit;
   }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        memset(t,-1,sizeof(t));
        return solve(prices,0,true,n);
    }
};