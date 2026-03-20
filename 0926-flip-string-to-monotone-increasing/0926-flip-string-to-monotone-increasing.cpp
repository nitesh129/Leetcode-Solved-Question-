class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n =  s.length();
        int flips =0;
        int tot_one =0;
        for(int i=0;i<n;i++){
            if(s[i] == '0' && tot_one >0){
                flips = min(flips+1 , tot_one);
            }
            else if(s[i]=='1'){
                tot_one++;
            }
        }
        return flips;
    }
};