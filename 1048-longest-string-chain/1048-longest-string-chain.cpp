class Solution {
public:
    int t[1001][1001];
    bool ispredecessor(string &a , string &b){
        if(b.length() != a.length() + 1) return false;
        int i=0 , j=0;
        int skip =0;
        while(i<a.length() && j<b.length()){
           if(a[i]==b[j]){
               i++;
               j++;
           }
           else{
              j++;
              skip++;
              if(skip>1) return false;
           }
        }
       return true;

    }
    int solve(int indx , int prev ,vector<string>& words,int n){
        if(indx>=n) return 0;
        int take =0;
        int not_take =0;
        if(t[indx][prev+1]!=-1) return t[indx][prev+1];
        if(prev==-1 || ispredecessor(words[prev],words[indx])){
            take = 1 + solve(indx+1,indx,words,n);
        }
        not_take = solve(indx+1,prev,words,n);
        return t[indx][prev+1] =  max(take,not_take);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        memset(t,-1,sizeof(t));
        sort(begin(words),end(words),[](string &a , string &b){
            return a.length() < b.length();
        });
        return solve(0,-1,words,n);
    }
};