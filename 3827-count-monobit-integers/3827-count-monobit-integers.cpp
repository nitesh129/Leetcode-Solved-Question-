class Solution {
public:
    int countMonobit(int n) {
        int cnt = 1;
        int k=1;
        while((1<<k) -1 <=n){
            cnt++;
            k++;
        }
        return cnt;
    }
};