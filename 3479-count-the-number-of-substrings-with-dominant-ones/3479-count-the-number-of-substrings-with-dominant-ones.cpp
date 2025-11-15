class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>countone(n,0);
        countone[0] = (s[0]=='1'?1:0);
        for(int i=1;i<n;i++){
            countone[i] = countone[i-1] + ((s[i]=='1') ? 1 : 0);
        }
        int result =0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int count_one = countone[j] - (i-1>=0 ? countone[i-1] : 0);
                int count_zero = (j-i+1) - count_one;
                if((count_zero*count_zero) > count_one){
                    int jump = count_zero*count_zero - count_one;
                    j+=jump-1;
                }
                else if((count_zero*count_zero)==count_one){
                     result+=1;
                }
                else{
                    result+=1;
                    int k = sqrt(count_one) - count_zero;
                    int next = j +k;
                    if(next>=n) {
                        result += (n-j-1);
                        break;
                    }
                    else{
                        result+=k;
                    }
                    j=next;
                }
            }
        }
        return result;
    }
};