class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int start_with_zero =0;
        int start_with_one =0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]=='0'){
                    start_with_one++;
                }
                else start_with_zero++;
            }
            else{
                if(s[i]=='1'){
                    start_with_one++;
                }
                else{
                    start_with_zero++;
                }
            }
        }
        return min(start_with_one , start_with_zero);
    }
};