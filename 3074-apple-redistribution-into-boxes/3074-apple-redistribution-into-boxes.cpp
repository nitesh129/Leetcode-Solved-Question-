class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(begin(capacity),end(capacity),greater<int>());
        int sum=0;
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        int count =0;
        for(int i=0;i<capacity.size();i++){
            if(sum>0){
                sum-=capacity[i];
                count++;
            }
            else break;
        }
        return count;

    }
};