class Solution {
public:
    int M = 1e9+7;
    int fact(int n){
        long long product = 1;
       for(long long  i=n;i>=1;i--){
            product = (product*i)%M;
       }
       return product;
    }
    int countPermutations(vector<int>& complexity) {
        // sort(begin(complexity) , end(complexity));
        int n = complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i] <= complexity[0]) return 0;
        }
        return fact(n-1)%M;


    }
};